/*
You are given an array A with size N (indexed from 0) and an integer K. 
Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.

For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.

You have to find the maximum subarray sum of the array B. Fomally, 
you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

Input
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A0, A1, ..., AN-1.
Output
For each test case, print a single line containing the maximum subarray sum of B.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ K ≤ 105
-106 ≤ Ai ≤ 106 for each valid i
Subtasks
Subtask #1 (18 points): N · K ≤ 105

Subtask #2 (82 points): original constraints

Example
Input:

2
2 3
1 2
3 2
1 -2 1

Output:

9
2
Explanation
Example case 1: B = {1, 2, 1, 2, 1, 2} and 
the subarray with maximum sum is the whole {1, 2, 1, 2, 1, 2}. Hence, the answer is 9.

Example case 2: B = {1, -2, 1, 1, -2, 1} and 
the subarray with maximum sum is {1, 1}. Hence, the answer is 2.
*/

// command is g++ -o KCON kadaneAlgorithm.cpp KCON.cpp
#include<bits/stdc++.h>
using namespace std;

extern int kadane(int* input, int n);

int KCON(int* input, int N, int M){
    int kadaneAns = kadane(input, N);
    int totalSum = 0;
    int bestPrefixSum = 0, bestSuffixSum = 0, currentPrefixSum = 0, currentSuffixSum = 0;
    for(int i = 0; i < N; i++){
        currentPrefixSum = currentPrefixSum + input[i];
        if(bestPrefixSum < currentPrefixSum){
            bestPrefixSum = currentPrefixSum;
        }
    }
    totalSum = currentPrefixSum;
    for(int i = N-1; i >= 0; i--){
        currentSuffixSum = currentSuffixSum + input[i];
        if(bestSuffixSum < currentSuffixSum){
            bestSuffixSum = currentSuffixSum;
        }
    }
    if(totalSum < 0){
        return max(kadaneAns, bestSuffixSum + bestPrefixSum);
    }else{
        return max(kadaneAns, bestSuffixSum + bestPrefixSum + (M-2)*totalSum);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int N,M;
        cin >> N >> M;
        int* input = new int[N];
        for(int i = 0; i < N; i++){
            cin >> input[i];
        }
        cout << KCON(input, N, M) << endl;
    }
}