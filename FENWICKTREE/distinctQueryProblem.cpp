/*
Distinct Query Problem
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. 
A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), 
you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output
For each d-query (i, j), print the number of distinct elements in the 
subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
3
2
3 
*/

/* to solve this problem the idea we planned is */
/* we first solve that queries which ends early(low end index) */
//(IF REPETITION OCCURS !!!!!)
/* then in later query if any element repeating then nullify the effect of early repetitive element */
/* then add effect of latest repetitive element */

#include<bits/stdc++.h>
using namespace std;

struct coder
{
	int first,second,index;
}query[200000];

bool operator < (coder A, coder B){
	
	return A.second < B.second;
}
/* this will be the fenwick tree */
int bit[30001];
void update(int index,int value,int n){

	for(;index<=n;index += index &(-index)){
		bit[index] += value;
	}
}
/* this will keep the track weather the element is appeared earlier in the history */
int last[1000001];
/* this is the array on which we will perform query operation */
int arr[30001];

int value(int index){

	int res= 0;
	for(;index >0 ;index -= index & (-index)){
		res += bit[index];
	}
	return res;
}

int main(){
	int n;
	cin >> n;	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}

	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>query[i].first>>query[i].second;
		query[i].index = i;
	}
	/* we will sort the query array based on the finish index */
	sort(query,query+q);
	/* initialize last array to -1 */
	memset(last,-1,sizeof(last));
	/* variable k will keep track of finish index of query */
    /* finish index must be equal to i */
	int k=0;
	int ans[q];
	/* this variable will keep count of distinct element starting from 0 to i */
	int total = 0;
	for(int i=1;i<=n;i++){
			
		if(last[arr[i]] != -1){
            /* it means that element arr[i] is already present */
            /* so we will make contribution of earlier arr[i] NIL */
            /* wherever arr[i](previous one) is adding to tree node we will substract -1 */
			update(last[arr[i]],-1,n);
		}else{
            /* we found a unique element */
			total++;
		}
		/* at this point we are done with all the adjustment required */
        /* we eliminated the effect of earlier arr[i](which is repeating element) */
        /* again update tree but with the new index i with 1*/
		update(i,1,n);
        /* last will contain the latest index of the element */
		last[arr[i]] = i;
	
		while(k<q && query[k].second == i){
			/* here we are storing the ans in the order of input */
			ans[query[k].index] = total - value(query[k].first-1);
			k++;

		}
		
	}


	for(int i=0;i<q;i++){
		cout << ans[i] <<endl;
	}
	return 0;
}