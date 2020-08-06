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