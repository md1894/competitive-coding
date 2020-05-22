#include<bits/stdc++.h>
using namespace std;

/* whenever you feel like you forgot this concept and you have to revise */
/* build the fenwick tree on the example */
/*
size --> 7
elements --> 1,3,5,11,7,4,6,9
*/

void update(int index, int value, int* IBST,int n){
    /* for update we have to change the value at node index and other node that includes index */
    /* we reach at other node by incrementing it logically */
    for(;index <= n; index = index + (index&(-index))){
        IBST[index] += value;
    }
}

int query(int index, int* IBST){
    int sum = 0;
    /* for query we collect the values present starting at index and all its parent */
    /* we move to the parent of current node by decrementing logic */
    for(;index > 0; index = index - (index&(-index))){
        sum += IBST[index];
    }
    return sum;
}


/* this IBST(fenwick tree) contains the sum of first i elements*/
int main(){
    int n;
    cin >> n;
    int* input = new int[n+1]();
    /* init all to zero */
    int* IBST = new int[n+1]();
    for(int i = 1; i < n+1; i++){
        cin >> input[i];
        /* one by one we insert element into the fenwick tree */
        update(i,input[i],IBST,n);
    }
    cout << "the answer for first 5 element is " << query(5,IBST) << endl;
    cout << "the answer for 2 to 5 inclusive is " << query(5,IBST) - query(1,IBST) << endl;
    cout << "the answer for 4 to 6 inclusive is " << query(6,IBST) - query(3,IBST) << endl;
    delete [] input;
    delete [] IBST;
    return 0;
}