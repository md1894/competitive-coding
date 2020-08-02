#include <bits/stdc++.h>
using namespace std;
const int n = 10000000;
bitset<10000005> b;
vector<int> primes;
typedef long long int ll;

void seive()
{
    // set all bits of bitset to 1
    b.set();
    for (ll i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                b[j] = 0;
            }
        }
    }
}

int main()
{
    seive();
    for (int i = 0; i < 100; i++)
    {
        cout << primes[i] << " ";
    }
    return 0;
}