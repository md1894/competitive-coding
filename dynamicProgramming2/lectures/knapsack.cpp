/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and ith item weigh wi and is of value vi. 
What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){
	int** dp = new int*[2];
    dp[0] = new int[maxWeight+1];
    dp[1] = new int[maxWeight+1];
    for(int i = 0; i <= maxWeight; i++){
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= maxWeight; j++){
            if(i%2 == 0){
                //exclude this item
                dp[0][j] = dp[1][j];
                if(weights[i] <= j){
                    // include this item
                    // take max of include item and exclude item case
                    dp[0][j] = max(dp[0][j], values[i] + dp[1][j-weights[i]]);
                }
            }else{
                // exclude this item
                dp[1][j] = dp[0][j];
                if(weights[i] <= j){
                    // include this item
                    // take max of include item and exclude item case
                    dp[1][j] = max(dp[1][j], values[i] + dp[0][j-weights[i]]);
                }
            }
        }
    }
    /* because n-1 will be the last entry, after that no computations will be performed */
    int ans = ((n-1)%2 == 0) ? dp[0][maxWeight] : dp[1][maxWeight];
    delete [] dp[0];
    delete [] dp[1];
    delete [] dp;
    return ans;
}


int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}