/*


Fibonacci series is well-known series in which in which each number (Fibonacci number) is the sum of the two preceding numbers. 
The series looks like 1, 1, 2, 3, 5, 8…. and so on. Your task is to find nth number.
Since the number can be large, output the answer modulo (109+7).
Input Format

An integer T, denoting the number of test cases. Each test case contains and integer N.
Constraints

1<=T<=10^5
1<=N<=10^9
Output Format

Print the nth Fibonacci number modulo (109+7).

Sample Input

4
3
4
5
6

Sample Output

2
3
5
8

Explanation

These terms are given in problem description.

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
		ll n;
		cin >> n;
		cout << compute(n) << endl;
	}
	return 0;
}
