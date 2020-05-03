/*
Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int* input, int n, int k){
    bool** dp = new bool*[n+1];
    for(int i = 0; i < n+1; i++){
        dp[i] = new bool[k+1];
    }
    for(int i = 0; i <= k; i++){
        dp[0][i] = false;
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if(input[i-1] <= j){
                dp[i][j] = dp[i][j] || dp[i-1][j-input[i-1]];
            }
        }
    }
    bool ans = dp[n][k];
    for(int i = 0; i <= n; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    int n,k;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    cin >> k;
    if(subsetSum(input, n, k)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
