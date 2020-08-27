/*

Extended Euclidean Algorithm:
Extended Euclidean algorithm also finds integer coefficients x and y such that:

ax + by = gcd(a, b) 

Examples:

Input: a = 30, b = 20
Output: gcd = 10
        x = 1, y = -1
(Note that 30*1 + 20*(-1) = 10)

Input: a = 35, b = 15
Output: gcd = 5
        x = 1, y = -2
(Note that 35*1 + 15*(-2) = 5)

*/

#include <bits/stdc++.h>
using namespace std;

// int x, y, GCD;

// void extended_euclid_algo(int a, int b)
// {
//     if (b == 0)
//     {
//         x = 1;
//         y = 0;
//         GCD = a;
//         return;
//     }
//     extended_euclid_algo(b, a % b);
//     int cX = y;
//     int cY = x - (a / b) * y;
//     x = cX;
//     y = cY;
// }



int extended_euclid_algo(int a, int b, int &x, int &y){
    // base case
    if(b == 0){
        // aX + bY = GCD(a, b);
        // as b == 0
        // aX = GCD(a, b) 
        // means x == 1, [ because in this case GCD(a, 0) == a ]
        y = 0;
        x = 1;
        return a;
    }
    int GCD = extended_euclid_algo(b, a%b, x, y);
    // first we evaluated new x, y (x1, y1) using old x, y
    int cX = y;
    int cY = x - (a/b) * y;
    // update the x, y
    x = cX;
    y = cY;
    return GCD;
}


int main()
{
    int x, y;
    int GCD = extended_euclid_algo(30, 20, x, y);
    cout << "(" << x << "," << y << ")"
         << " GCD IS -> " << GCD << endl;
    return 0;
}
