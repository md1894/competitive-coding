/*

//string utility

#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    a = "57896";
    for(int i = 0; a[i] != 0; i++){
        cout << a[i] - 48 << " x 10^" << a.length() - i - 1<<endl;
    }
    return 0;
}

*/

/*
Alice recently learnt calculating greatest common divisor. 
Now Bob wants to test his knowledge and gives him two numbers 
(one of them being extremely large) 
to calculate gcd. Alice needs your help to finish this task.

Input Format
Single line containing two integral values (N and M).

Constraints
0<=N<=10^7 and N <= M < 10^250

Output Format
Print the Greatest Common Divisor of two numbers.

Sample Input
3 9
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fast_power(ll a, ll n){
	if(n == 0){
		return 1;
	}
	/* breaking the problem into halfs */
	ll subProblem = fast_power(a,n/2);
	/* if n is odd */
	if(n&1){
		return a*subProblem*subProblem;
	}
	/* if n is even */
	return subProblem*subProblem;
}

ll fastModExp(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}

ll euclid_GCD(ll a, ll b){
    if(b == 0)
        return a;
    else
        return euclid_GCD(b, a%b);
}

ll bigGCD(ll n, string m) {
    ll y = 0;
    for(int i = 0; m[i] != 0; i++){
        y = (y + ((m[i] - 48)*fastModExp(10, m.length()-i-1, n))) % n;
    }
    return euclid_GCD(y, n);
}

int main(){
    ll n;
    string m;
    cin >> n >> m;
    cout << bigGCD(n, m) << endl;
    return 0;
}