/*
Roy and Coin Boxes
Send Feedback
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;


void fillItWithAns(int n, int m, int* first, int* second, int* dp){
    int* totalCoinsInBox = new int[n+1];
    int* freqOfTotalCoins = new int[n+1];
    for(int i = 0; i <= n; i++){
        totalCoinsInBox[i] = 0;
        freqOfTotalCoins[i] = 0;
    }
    totalCoinsInBox[1] = first[1];
    for(int i = 2; i <= n; i++){
        totalCoinsInBox[i] = totalCoinsInBox[i-1] + first[i] - second[i-1];
    }
    for(int i = 1; i <= n; i++){
        freqOfTotalCoins[totalCoinsInBox[i]]++;
    }
    dp[n] = freqOfTotalCoins[n];
    for(int i = n-1; i > 0; i--){
        dp[i] = dp[i+1] + freqOfTotalCoins[i];
    }
    delete [] totalCoinsInBox;
    delete [] freqOfTotalCoins;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    int* first = new int[n+1];
    int* second = new int[n+1];
    for(int i = 0; i < m; i++){
        int f, s;
        cin >> f >> s;
        first[f]++;
        second[s]++;
    }
    int* dp = new int[n+1];
    fillItWithAns(n,m,first,second,dp);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int query;
        cin >> query;
        cout << dp[query] << endl;
    }
    delete [] dp;
    delete [] first;
    delete [] second;
    return 0;
}