/*


The Fibonacci sequence is defined by the following relation:
F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. 
Given two non-negative integers N and M, 
you have to calculate the sum (F(N) + F(N + 1) + … + F(M)) mod 1000000007.
Source: FIBOSUM (SPOJ)

Input Format

The first line contains an integer T (the number of test cases). 
Then, T lines follow. Each test case consists of a single line with two non-negative integers N and M.
Constraints

1<=T<=1000 
0<=N<=M<=10^9

Output Format
For each test case you have to output a single line containing the answer for the task.

Sample Input
3
0 3
3 5
10 19

Sample Output
4
10
10857

*/

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long int ll;

/* k here is 2 , hence we create a matrix of 3x3 , 1 indexed */

/* this is a simple matrix multiplication logic */
/* please note that matrix starts at 1,1 */
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
   vector<vector<ll>> C(2+1,vector<ll>(2+1));
   for(ll i = 1; i <= 2; i++){
      for(ll j = 1; j <= 2; j++){
         for(ll x = 1; x <= 2; x++){
            C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
         }
      }
   }
   return C;
}

/* calculating power of a matrix using fast exponentiation logic */
vector<vector<ll>> pow(vector<vector<ll>> T, ll n){
   if(n == 1)
      return T;
   
   if(n&1){
      return multiply(T,pow(T,n-1));
   }
   vector<vector<ll>> X = pow(T,n/2);
   return multiply(X,X);
}


ll compute(ll n){
   if(n == 1 || n == 2)
      return 1;

   /* building F1 vector which is starting from index 1 */
   vector<ll> F1 = vector<ll>(2+1);
   /* As First 2 terms are 1, 1 */
   F1[1] = 1;
   F1[2] = 1;

   vector<vector<ll>> T(2+1,vector<ll>(2+1));
   /* logic to build a 2D transformation matrix */
   T[1][1] = 0;
   T[1][2] = 1;
   T[2][1] = 1;
   T[2][2] = 1;

   T = pow(T,n-1);

   ll res = 0;
   /* follow the pdf in that pdf it is given that the first element of T^(n-1)*F1 is the ans */
   for(ll i = 1; i <= 2; i++){
      res  = (res + (T[1][i]*F1[i])%MOD)%MOD;
   }
   return res;
}


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
    /* mathematical relation for the sum of fibonacci number */
		cout << (compute(m+2)%MOD - compute(n+1)%MOD + MOD)%MOD << endl;
	}
	return 0;
}


