/*
Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, 
sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : 
{1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minCount(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        int count = INT_MAX;
        for(int j = 1; j <= i; j++){
            if((i-(j*j)) < 0){
                break;
            }
            count = min(count, dp[i-j*j]);
        }
        dp[i] = 1 + count;
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}

int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    return 0;
}