/*
Distinct Subsequences
Send Feedback
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). 
For the uninformed, A subsequence of a string is a new string which is formed from the original string 
by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. 
You are required to process all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. 
Ith line in the output corresponds to the number of distinct subsequences of ith input string. 
Since, this number could be very large, 
you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496
*/


#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/* dry run this algorithm on string 'AAA' and 'ABC' */
/* you will recall and study this kind of problem solving */
int distinctSubSequence(string input){
    int m = input.length();
    int* dp = new int[m+1];
    dp[0] = 1;
    int last[27];
    for(int i = 0; i <= 26; i++){
        last[i] = -1;
    }
    /* also try to build the brute force solution to this problem */
    for(int i = 1; i <= m; i++){
        dp[i] = (2*(long)dp[i-1]) % MOD;
        if(last[input[i-1] - 'A'] != -1){
            dp[i] = (dp[i] - dp[last[input[i-1]-'A']] + MOD) % MOD;
        }
        last[input[i-1]-'A'] = i-1;
    }
    int ans = dp[m];
    delete [] dp;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        cout << distinctSubSequence(input) << endl;
    }
    return 0;
}