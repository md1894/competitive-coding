/*

Chinese Remainder Theorem | Set 2 (Inverse Modulo based Implementation)

x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of  pp[i] with respect to num[i]




Let us take below example to understand the solution


num[] = {3, 4, 5}, rem[] = {2, 3, 1}
prod  = 60 
pp[]  = {20, 15, 12}
inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1, (12*3)%5 = 1

x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + rem[2]*pp[2]*inv[2]) % prod
  = (2*20*2 + 3*15*3 + 1*12*3) % 60
  = (40 + 135 + 36) % 60
  = 11

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll extendedEuclidAlgorithm(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        y = 0;
        x = 1;
        return a;
    }
    ll gcd = extendedEuclidAlgorithm(b, a%b, x, y);
    ll tempX = y;
    ll tempY = x - (a/b)*y;
    x = tempX;
    y = tempY;
    return gcd;
}


void get_mod_mul_inv(int inv[], int num[], int k){
    int product = 1;
    for(int i = 0; i < k; i++){
        product = product*num[i];
    }
    for(int i = 0; i < k; i++){
        ll x, y;
        extendedEuclidAlgorithm(product/num[i],num[i], x, y);
        inv[i] = (x % num[i] + num[i]) % num[i];
    }
}

int findMinX(int num[], int rem[], int k){
    int inv[k];
    int product = 1;
    get_mod_mul_inv(inv, num, k);
    for(int i = 0; i < k; i++){
        product = product*num[i];
    }
    // Initialize result 
    int result = 0; 
  
    // Apply above formula 
    for (int i = 0; i < k; i++) 
    { 
        int pp = product / num[i]; 
        result += (rem[i] * inv[i] * pp);
    }
  
    return result % product; 
}

// Driver method 
int main(void) 
{ 
    int num[] = {3, 4, 5}; 
    int rem[] = {2, 3, 1}; 
    int k = sizeof(num)/sizeof(num[0]); 
    cout << "x is " << findMinX(num, rem, k) << endl; 
    return 0; 
} 


