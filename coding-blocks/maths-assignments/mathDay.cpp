/*
Math Day is being celebrated at Coding Blocks. 
So Prateek Bhaiya rolled out a contest on Maths Problems. Here goes one.
Given three positive integers A,N,P. Compute AN! %P.


Input Format
The first line of the input gives the number of test cases, T. T lines follow.
Each line contains three integers A, N and P, as described above.

Constraints
1 ≤ T ≤ 100 1 ≤ A ≤ 10^5. 1 ≤ N ≤ 10^5. 1 ≤ P ≤ 10^5.

Output Format
For every test case, print the answer in a new line.

Sample Input
2
2 1 2
3 3 2
Sample Output
0
1
Explanation
In first case, the answer is the remainder when 2^1! = 2 is divided by 2, which is 0. 
In second case , the answer is the remainder when 3^3! = 36 = 729 is divided by 2, which is 1.
*/


/*
// this code has accepted
#include<bits/stdc++.h>
#define ll long long
using namespace std;




ll calculate_ans(ll c,ll k,ll p){
    if(k==1){
        return c;
    }
    ll ans=calculate_ans(c,k/2,p);
    if(k%2)
    return ((ans%p)*(ans%p)*c)%p;
    return ((ans%p)*(ans%p))%p;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll a,n,p;
        cin>>a>>n>>p;
        ll ans=1;
        while(n){
            a=calculate_ans(a,n,p)%p;
            n--;
        }
        cout<<a<<endl;
    }
	return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastModExp(ll a, ll b, ll m){
	ll res = 1;
    while(b>0){
        if(b&1){
            //res = (res*a)%m;
            res = ((res % m) * (a % m)) % m;
        }
        // a = (a*a)%m;
        a = ((a % m) * (a % m)) % m;
        b = b >> 1;
    }
    return res;
}

int main() {
    ll t,a,n,p;
    cin >> t;
    while(t--){
        cin >> a >> n >> p;
        // ll ans = a;
        // for(int i = 2; i <= n; i++){
        //     ans = fastModExp(ans,i,p);
        // }
        // //cout << fastModExp(a,n,p) << endl;
        // cout << ans << endl;
        while(n > 0){
			a = fastModExp(a, n, p);
			n--;
		}

        cout<<a<<endl;
    }
	return 0;
}