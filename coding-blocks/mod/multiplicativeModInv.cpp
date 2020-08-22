/*
Given two integers ‘a’ and ‘m’, 
find modular multiplicative inverse of ‘a’ under modulo ‘m’.
The modular multiplicative inverse is an integer ‘x’ such that.

a x ≡ 1 (mod m) 

The value of x should be in {0, 1, 2, … m-1}, 
i.e., in the range of integer modulo m.

The multiplicative inverse of “a modulo m” exists if and only if 
a and m are relatively prime (i.e., if gcd(a, m) = 1).

EXAMPLES::

Input:  a = 3, m = 11
Output: 4

Since (4*3) mod 11 = 1, 4 is modulo inverse of 3(under 11).
One might think, 15 also as a valid output as "(15*3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not 
valid.

Input:  a = 10, m = 17
Output: 12

Since (10*12) mod 17 = 1, 12 is modulo inverse of 10(under 17).

*/


#include<bits/stdc++.h>
using namespace std;

int extendedEuclidAlgorithm(int a, int b, int &x, int &y){
    if(b == 0){
        y = 0;
        x = 1;
        return a;
    }
    int gcd = extendedEuclidAlgorithm(b, a%b, x, y);
    int tempX = y;
    int tempY = x - (a/b)*y;
    x = tempX;
    y = tempY;
    return gcd;
}


int main(){
    int a, m;
    cin >> a >> m;
    int x, y;
    int GCD = extendedEuclidAlgorithm(a, m, x, y);
    if(GCD != 1){
        cout << "MULTIPLICATIVE MODULAR INVERSE DOES NOT EXSIST " << endl;
    }else{
        int ans = (x%m + m)%m;
        cout << "MULTIPLICATIVE MODULAR INVERSE IS " << ans << endl;
    }
    return 0;
}