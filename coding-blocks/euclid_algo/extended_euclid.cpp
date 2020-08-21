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

int x, y, GCD;

void extended_euclid_algo(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    extended_euclid_algo(b, a % b);
    int cX = y;
    int cY = x - (a / b) * y;
    x = cX;
    y = cY;
}

int main()
{
    extended_euclid_algo(30, 18);
    cout << "(" << x << "," << y << ")"
         << " GCD IS -> " << GCD << endl;
    return 0;
}
