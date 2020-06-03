/*
SUBSUMS - Subset Sums
#binary-search #bitmasks

Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S (including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.
Input

The first line of standard input contains the three integers N, A, and B. The following N lines contain S1 through SN, in order.
Output

Print a single integer to standard output representing the number of subsets satisfying the above property. Note that the answer may overflow a 32-bit integer.
Example

Input:
3 -1 2
1
-2
3

Output:
5

The following 5 subsets have a sum between -1 and 2:

    0 = 0 (the empty subset)
    1 = 1
    1 + (-2) = -1
    -2 + 3 = 1
    1 + (-2) + 3 = 2


*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
this function will extract the subset and calculate the sum then add it to the ans
*/
void subsets(vector<ll> input, vector<ll>& sv){
	/* sv will hold the ans */
	ll n = input.size();
	for(ll i = 1; i < (1<<n); i++){
		ll sum = 0;
		ll j = 0;
		for(int no = i; no > 0; j++,no = no>>1){
			if(no&1){
				sum += input[j];
			}
		}
		sv.push_back(sum);
		
	}
}


/*
to solve this problem we divided the total combinations 2^34 into the set of 2
v1 --> can hold max of 2^17 combinations
v2 --> can hold max of 2^17 combinations
we calculate subset_sum for each list of elements v1 and v2 in sv2 , sv1
we sort one of them 
a = 3, b = 9 and sv1 --> {6,1,4} and sv2--> {1,2,3}
so if i take sv1[1] == 6 i can get {6,1} {6,2} {6,3}
*/
int main()
{
	ll n,a,b;
	vector<ll> v1,v2,sv1,sv2;
	cin>>n>>a>>b;
	ll n1 = n/2;
	ll n2 = n - n1;
	for(ll i = 0; i < n1; i++){
		ll num;
		cin >> num;
		v1.push_back(num);
	}
	for(ll i = 0; i < n2; i++){
		ll num;
		cin >> num;
		v2.push_back(num);
	}
	subsets(v1,sv1);
	subsets(v2,sv2);
	sort(sv2.begin(),sv2.end());
	ll ans = 0;
	for(ll i = 0; i < sv1.size(); i++){
		ll st = a - sv1[i];
		ll en = b - sv1[i];
		vector<ll>::iterator it1 = lower_bound(sv2.begin(),sv2.end(),st);
		vector<ll>::iterator it2 = upper_bound(sv2.begin(),sv2.end(),en);
		ll l = it2 - sv2.begin();
		ll k = it1 - sv2.begin();
		ans += (l-k);
	}
	for(ll i = 0; i < sv1.size(); i++){
		if(a <= sv1[i] && sv1[i] <= b){
			ans++;
		}
	}

	// including subset sums from 2nd set
        for(ll i = 0; i < sv2.size(); i++){
		
            if(a <= sv2[i] && sv2[i] <= b){
                ans++;
            }
        }

	// also including empty set if it lies in give range(a,b)
	if(a <= 0 && 0 <= b){
		ans++;
	}
	
    	cout<<ans<<endl;
	return 0;
}
