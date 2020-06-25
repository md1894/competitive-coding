/*
Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1*(ai-1) + c2*(ai-2) + ... + ck*(ai-k)    (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. 
Your task is to compute an for given n and output it modulo 109.

Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)

Output
Exactly C lines, one for each test case: an modulo 109

Example
Input:
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

Output:
8 
714 
257599514
*/

#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;

typedef long long ll;

vector<ll> a, b, c;
ll k;

/* this is a simple matrix multiplication logic */
/* please note that matrix starts at 1,1 */
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
   vector<vector<ll>> C(k+1,vector<ll>(k+1));
   for(ll i = 1; i <= k; i++){
      for(ll j = 1; j <= k; j++){
         for(ll x = 1; x <= k; x++){
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
   if(n == 0)
      return 0;

   if(n <= k)
      return b[n-1];
   /* building F1 vector which is starting from index 1 */
   vector<ll> F1 = vector<ll>(k+1);
   for(ll i = 1; i <= k; i++){
      F1[i] = b[i-1];
   }

   vector<vector<ll>> T(k+1,vector<ll>(k+1));
   /* logic to build a 2D transformation matrix */
   for(ll i = 1; i <= k; i++){
      for(ll j = 1; j <= k; j++){
         if(i < k){
            if(j == i+1){
               T[i][j] = 1;
            }else{
               T[i][j] = 0;
            }
         }else{
            T[i][j] = c[k-j];
         }
      }
   }

   T = pow(T,n-1);

   ll res = 0;
   /* follow the pdf in that pdf it is given that the first element of T^(n-1)*F1 is the ans */
   for(ll i = 1; i <= k; i++){
      res  = (res + (T[1][i]*F1[i])%MOD)%MOD;
   }
   return res;
}


int main(){
   ll t,n,num;
   cin >> t;
   while(t--){
      cin >> k;
      for(ll i = 0; i < k; i++){
         cin >> num;
         b.push_back(num);
      }
      for(ll i = 0; i < k; i++){
         cin >> num;
         c.push_back(num);
      }
      cin >> n;
      cout << compute(n) << endl;
      b.clear();
      c.clear();
   }
   return 0;
}
