/*
Balika Vadhu- Problem
Send Feedback
Anandi and Jagya were getting married again when they have achieved proper age. 
Dadi Sa invited Alok Nath to do the kanyadaan and give blessings. Alok Nath has 2 blessings. 
Each bessing is in the form of a string consisting of lowercase charaters(a-z) only. 
But he can give only one blessing of K length because some priest told him to do so. 
Thus he decides to generate a blessing using the other two blessings. 
While doing this he wants to ensure that happiness brought into their life by his blessing is maximum.
The generated blessing is a common subsequence of length K of the two blessings he has. 
Happiness of the blessing he generates is calculated by the sum of ASCII values of characters in the blessing and he wants the happiness to be maximum. 
If he is not able to generate a common subsequence of length K then the happiness is 0 (zero). 
Alok Nath comes to you and asks you to find the maximum happiness that can be generated by the two blessings he has.
Input Specification
First line consists of number of test cases t. 
Each test case consists of two strings b1 (blessing 1),b2 (blessing 2) and an integer K, 
each of them in separate lines.
Output Specification
Output consists of t lines each containing an integer denoting the maximum happiness value 
that can be generated by the two blessings.
Constraint
1 <= t <= 50

1 <= length(b1) , length(b2) <= 100 

1 <= K <= 100
Sample Input
2
asdf
asdf
3
anandi
jagya
3
Sample Output
317
0
*/

#include <bits/stdc++.h>
using namespace std;


int balikaVadhu(string b1, string b2, int k_){
    int m = b1.length();
    int n = b2.length();
    /* creating a dp array of m-n-k_ */
    int*** dp = new int**[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = new int*[n+1];
        for(int j = 0; j <= n; j++){
            dp[i][j] = new int[k_+1];
        }
    }
    /* filling all the cells with zero */
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= k_; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= k_; k++){
                if(k > i || k > j){
                    continue;
                }
                if(b1[i-1] == b2[j-1]){
                    int option1 = b1[i-1] + dp[i-1][j-1][k-1];
                    int option2 = dp[i-1][j][k];
                    int option3 = dp[i][j-1][k];
                    dp[i][j][k] = max(option1,max(option2,option3));
                }else{
                    int option1 = dp[i-1][j][k];
                    int option2 = dp[i][j-1][k];
                    dp[i][j][k] = max(option1,option2);
                }
            }
        }
    }
    /* deallocating the dp array */
    int ans = dp[m][n][k_] == -1 ? 0 : dp[m][n][k_];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
 	int t;
    cin >> t;
    while(t--){
        string b1, b2;
        int k_;
        cin >> b1 >> b2 >> k_;
        cout << balikaVadhu(b1, b2, k_) << endl;
    }
    return 0;
}
