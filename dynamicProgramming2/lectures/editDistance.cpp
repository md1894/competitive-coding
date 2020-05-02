/*
Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
Edit Distance of two strings is minimum number of steps required to make one string equal to other. 
In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    int** dp = new int*[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = new int[n+1];
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= m; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]){
                /*
                if first character matches then there will be no cost, directly
                move to next sequence of problem
                */
                dp[i][j] = dp[i-1][j-1];
            }else{
                /*
                if replace --> then first character will match, and both strings will be 
                               one character less
                if delete --> then one string will be less by one character and 
                			  other will remain as it is
                if insert --> one string will be bigger by one char than the other
                */
                dp[i][j] = min(1 + dp[i-1][j-1], min(1 + dp[i][j-1], 1 + dp[i-1][j]));
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

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}