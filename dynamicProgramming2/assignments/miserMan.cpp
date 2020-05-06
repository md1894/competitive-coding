/*
MISERMAN - Wise And Miser
#dynamic-programming
Jack is a wise and miser man. Always tries to save his money.

One day, he wants to go from city A to city B. Between A and B, 
there are N number of cities(including B and excluding A) and in each city there are M buses 
numbered from 1 to M. And the fare of each bus is different. 
Means for all N*M busses, fare (K) may be different or same. 
Now Jack has to go from city A to city B following these conditions:

At every city, he has to change the bus.

And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.

You are to help Jack to go from A to B by spending the minimum amount of money.

N, M, K <= 100.

Input
Line 1:    N M
Line 2-:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.

Output
Single Line containing the minimum amount of fare that Jack has to give.

Example
Input:
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9

Output:
10
Explanation
1 -> 4 -> 1 -> 3 -> 1: 10
*/

#include <bits/stdc++.h>
using namespace std;

int miserMan(int** input, int n, int m){
    int** dp = new int*[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[m+1];
        for(int j = 0; j <= m; j++){
            dp[i][j] = INT_MAX;
        }
    }
    /* base case */
    for(int i = 1; i <= m; i++){
        dp[n-1][i] = input[n-1][i];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j <= m; j++){
            int op1 = (j-1 >= 1) ? input[i][j] + dp[i+1][j-1] : INT_MAX;
            int op2 = input[i][j] + dp[i+1][j];
            int op3 = (j+1 <= m) ? input[i][j] + dp[i+1][j+1] : INT_MAX;
            int ans = min(op1,min(op2,op3));
            dp[i][j] = ans;
        }
    }
    /* finding the minimum value from the first row */  
    int bestAns = INT_MAX;
    for(int i = 1; i <= m; i++){
        if(bestAns > dp[0][i]){
            bestAns = dp[0][i];
        }
    }
    for(int i = 0; i < n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return bestAns;
}

int main(){
    int n,m;
    cin >> n >> m;
    int** input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[m+1];
        input[i][0] = INT_MAX;
        for(int j = 1; j <= m; j++){
            cin >> input[i][j];
        }
    }
    cout << miserMan(input, n, m) << endl;
    for(int i = 0; i < n; i++){
        delete [] input[i];
    }
    delete [] input;
    return 0;
}