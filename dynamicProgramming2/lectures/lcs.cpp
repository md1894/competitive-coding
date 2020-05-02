/* largest common subsequence */
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

int lcs(char* s1, char* s2, int m, int n, int** dp){
    if(m == 0 || n == 0){
        return 0;
    }
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    int ans;
    if(s1[0] == s2[0]){
        ans = 1 + lcs(s1+1, s2+1, m-1,n-1,dp);
    }else{
        int option1 = lcs(s1+1, s2, m-1, n,dp);
        int option2 = lcs(s1, s2+1, m, n-1, dp);
        ans = max(option1, option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs(char* s1, char* s2){
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = new int*[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    return lcs(s1, s2, m, n, dp);
}

int main(){
    char s1[1000], s2[1000];
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    return 0;
}