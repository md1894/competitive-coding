/*
PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. 
Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). 
In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) 
separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, 
test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages 
(though most should be OK if the algorithm is well designed)
*/

#include <bits/stdc++.h>
#define N 100000
using namespace std;
typedef long long int ll;
int p[N + 1] = {0};
vector<int> primes;

void seive()
{
    for (int i = 2; i < N; i++)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= N; j += i)
            {
                p[j] == 1;
            }
        }
    }
}

int main()
{
    seive();
    int t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        bool segment[n - m + 1];
        for (int i = 0; i < (n - m + 1); i++)
        {
            segment[i] = 0;
        }
        for (int i = 0; i < primes.size(); i++)
        {
            if ((primes[i] * primes[i]) > n)
                break;

            int start = (m / primes[i]) * primes[i];
            if (primes[i] >= m && primes[i] <= n)
            {
                start = primes[i] * 2;
            }
            for (int j = start; j <= n; j += primes[i])
            {
                segment[j - m] = 1;
            }
        }
        for (int i = m; i <= n; i++)
        {
            if (segment[i - m] == 0 && i != 1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
