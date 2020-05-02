/* using dynamic programming */
/*
LCS - Problem
Send Feedback
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int** dp = new int*[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = new int[n+1];
    }
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ans = dp[m][n];
    for(int i = 0; i <= m; i++){
        delete [] dp[i];
    }
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    return 0;
}