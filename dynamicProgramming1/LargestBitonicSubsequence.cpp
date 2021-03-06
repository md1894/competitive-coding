/*
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include<bits/stdc++.h>
using namespace std; 	

int longestBitonicSubarray(int *input, int n) {
    int* incSub = new int[n];
    int* decSub = new int[n];
    for(int i = 0; i < n; i++){
        incSub[i] = 1;
        decSub[i] = 1;
    }
    
    //LIS
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(input[j] >= input[i]){
                continue;
            }
            int possibleAns = incSub[j] + 1;
            if(possibleAns > incSub[i]){
                incSub[i] = possibleAns;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << incSub[i] << " ";
    }
    cout << endl;

    //LDS
    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(input[j] >= input[i]){
                continue;
            }
            int possibleAns = decSub[j] + 1;
            if(possibleAns > decSub[i]){
                decSub[i] = possibleAns;
            }
        }
    }

    for(int i = 0; i < n; i++){
       cout << decSub[i] << " ";
    }
    cout << endl;
    int max = incSub[0] + decSub[0] - 1;
    for(int i = 1; i < n; i++){
        int currentAns = incSub[i] + decSub[i] - 1;
        if(currentAns > max){
            max = currentAns;
        }
    }
    delete [] incSub;
    delete [] decSub;
    return max;
}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n) << endl;
  return 0;
}