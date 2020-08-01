/*
PMO gives two random numbers a & b to the Prime Minister. 
PM Modi wants to visit all countries between a and b (inclusive) , 
However due to shortage of time he can't visit each and every country , 
So PM Modi decides to visit only those countries,for which country number has two divisors. 
So your task is to find number of countries Mr. Modi will visit.
Input Format
The first line contains N , no of test cases. 
The next N lines contain two integers a and b denoting the range of country numbers.

Constraints
a<=1000000 & b<=1000000.
N<=1000

Output Format
Output contains N lines each containing an answer for the test case.

Sample Input
2
1 10
11 20
Sample Output
4
4
Explanation
PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
For the second testcase , he chooses countries with numbers 11,13,17 and 19.

https://hack.codingblocks.com/app/practice/3/1039/problem

*/
#include <bits/stdc++.h>
#define N 1000001
using namespace std;

typedef long long int ll;

//loop condition
/*
suppose you have to check weather 36 is prime or not
possible divisors of 36 is 
1, 2, 3, 4,    '6' (sqrt(N))   , 9, 12, 18, 36
for each divisor of 36 greater tha sqrt(36) there is a corresponding divisor greater than sqrt(36)
so rather than checking weather there is any divisor in the range 1 to 36, (i.e. 1 to N)
we will check in the range 1 to 6, (i.e. sqrt(N))
*/

void prime_seive(int *p)
{
    //special case
    p[2] = 1;
    p[0] = p[1] = 0;
    //mark every odd number as a prime number
    //even number cannot be a prime number
    for (int i = 3; i < N; i += 2)
    {
        p[i] = 1;
    }
    // for the condition of this for loop please refer the above condition
    for (int i = 3; i * i < N; i += 2)
    {
        // if the number is a prime number
        // mark all of its multiples as not prime number
        if (p[i] == 1)
        {
            for (ll j = i * i; j < N; j += i)
            {
                p[j] = 0;
            }
        }
    }
    // at this stage we get the array whose index denotes weather that number is
    // prime or not
}

int main()
{
    ll q, a, b;
    cin >> q;
    int p[N] = {0};
    int csum[N] = {0};
    prime_seive(p);
    // compute the cummulative sum of primes upto N
    for (int i = 1; i < N; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }
    // answer all query in O(1) time
    while (q--)
    {
        cin >> a >> b;
        cout << csum[b] - csum[a - 1] << endl;
    }
    return 0;
}
