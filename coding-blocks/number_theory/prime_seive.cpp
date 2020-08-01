#include <bits/stdc++.h>
using namespace std;
void prime_seive(int *a)
{
    //skip all even numbers
    for (int i = 3; i <= 100000; i += 2)
    {
        a[i] = 1;
    }
    for (int i = 3; i * i <= 100000; i += 2)
    {
        if (a[i] == 1)
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                a[j] = 0;
            }
        }
    }
}

int main()
{
    int a[100001] = {0};
    prime_seive(a);
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        if (a[i] == 1)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}