/*
Sequence (ai) of natural numbers is defined as follows:

ai = bi (for i <= k)
ai = c1(a(i-1)) + c2(a(i-2)) + ... + ck(a(i-k)) (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. 
Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and 
output it modulo a given positive integer p.

Input
On the first row there is the number C of test cases (equal to about 50).
Each test contains four lines:
k - number of elements of (c) and (b) (1 <= k <= 15)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
m, n, p - natural numbers separated by spaces (1 <= m <= n <= 1018, 1<= p <= 108)
Output
Exactly C lines, one for each test case: (am + am+1 + am+2 + ... + an) modulo p.

Example
Input:
1
2
1 1
1 1
2 10 1000003

Output:
142
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/* please note that in the matrix_exponentiation problem the matrices are starting from index 1 */
/* but here the matrices are starting from index 0 */
vector<ll> b,c;
ll k,MOD;

/* for better understanding of the algorithm dry run this on fibonacci number sum from m to n */
/* choose any span */
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B){
   vector<vector<ll>> C(k+1,vector<ll>(k+1));
   for(ll i = 0; i <= k; i++){
      for(ll j = 0; j <= k; j++){
         for(ll x = 0; x <= k; x++){
            C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
         }
      }
   }
   return C;
}


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
    if(n <= k){
        ll result = 0;
        for(ll i = 0; i < k; i++){
            result += b[i];
            if(i+1 == n)
                return result;
        }
    }
    ll sum = 0;
    for(ll i = 0; i < k; i++){
        sum += b[i];
    }
    vector<ll> F1(k+1);
    /* this step is also important */
    for(ll i=0;i<=k;i++){
        if(i==0){
            F1[i]=sum;
        }
        else {
            F1[i]=b[i-1];
        }
    }
    vector<vector<ll>> T(k+1,vector<ll>(k+1));
    /* this logic to build the transformation matrix is the heart of problem */
    for(int i = 0; i < k+1; i++){
        for(int j = 0; j < k+1; j++){
            if(i == 0 && j == 0){
                T[i][j] = 1;
            }else if((i == 0 || i == k) && j > 0){
                T[i][j] = c[k-j];
            }else if(j == i+1){
                T[i][j] = 1;
            }else{
                T[i][j] = 0;
            }
        }
    }
    // cout << "b" << endl;
    // for(auto i: b){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "c" << endl;
    // for(auto i: c){
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "T" << endl;
    // for(ll i = 0; i <= k; i++){
    //     for(ll j = 0; j <= k; j++){
    //         cout << T[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    T = pow(T,n-k);
    // cout << "T" << endl;
    // for(ll i = 0; i <= k; i++){
    //     for(ll j = 0; j <= k; j++){
    //         cout << T[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // sum = 0;
    for(ll i = 0; i <= k; i++){
        sum  = (sum + (T[0][i]*F1[i])%MOD)%MOD;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> k;
        b.resize(k);
        c.resize(k);
        for(ll i = 0; i < k; i++){
            cin >> b[i];
        }
        for(ll i = 0; i < k; i++){
            cin >> c[i];
        }
        ll n,m;
        cin >> m >> n >> MOD;
        ll result = (compute(n)%MOD-compute(m-1)%MOD+MOD)%MOD;
        cout << result << endl;
    }
    return 0;
}
