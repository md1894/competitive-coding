/*
Count BSTs
Send Feedback
Given an integer N, find and 
return the count of unique Binary search trees (BSTs) are possible 
with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countBST(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    const int MOD = 1000000007;
    int* dp = new int [n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        int sum = 0;
        for(int k = 1; k <= i; k++){
             sum = ( sum%MOD + ((long)dp[k-1]*dp[i-k])%MOD ) %MOD;
        }
        dp[i] = sum;
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}


int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
