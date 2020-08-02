/*
                    CODEFORCES

A number is called almost prime if it has exactly two distinct prime divisors. 
For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. 
Find the amount of almost prime numbers which are between 1 and n, inclusive.

Input
Input contains one integer number n (1 ≤ n ≤ 3000).

Output
Output the amount of almost prime numbers between 1 and n, inclusive.

Examples
input
10
output
2

input
21
output
8
*/

#include <bits/stdc++.h>
#define N 3000
using namespace std;

/*
used the logic of seive to store how many prime divisors a number will have
*/
int seive(int n)
{
    int pr[n + 1] = {0};
    for (int i = 2; i <= n; i++)
        if (!pr[i])
            for (int j = i; j <= n; j += i)
                pr[j]++;

    int ans = 0;
    for (int i = 2; i <= n; i++)
        if (pr[i] == 2)
            ans++;

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << seive(n) << endl;
    return 0;
}
