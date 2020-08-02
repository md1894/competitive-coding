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

bool isPrime(ll num)
{
    if (num <= n)
    {
        return b[num] == 1 ? true : false;
    }
    for (ll i = 0; primes[i] * (ll)primes[i] <= num; i++)
    {
        if (num % primes[i] == 0)
            return false;
    }
    return true;
}

/*
the logic is if the input number is lessthan equal to the limit of seive then
evaluate it using seive, in O(1), as we have precomputed the seive
else evaluate it using for loop, that runs O(sqrt(num))
*/
int main()
{
    //2147483647
    seive();
    if (isPrime(2147483648))
    {
        cout << "yes it is a prime number" << endl;
    }
    else
    {
        cout << "Not a Prime Number" << endl;
    }
    return 0;
}