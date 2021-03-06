/*
All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

#include<iostream>
// #include "Solution.h"
using namespace std;


int allIndexes(int* input, int n, int x, int* output){
    if(n == 0)
        return 0;
    
    int ans = allIndexes(input+1,n-1,x,output);
    if(input[0] != x && ans == 0){
        return 0;
    }else if(input[0] != x && ans != 0){
        for(int i = 0; i < ans; i++){
            output[i]++;
        }
        return ans;
    }else if(input[0] == x && ans != 0){
        for(int i = ans; i > 0; i--){
            output[i] = output[i-1];
            output[i]++;
        }
        output[0] = 0;
        return 1 + ans;
    }else if(input[0] == x && ans == 0){
        output[0] = 0;
        return 1;
    }
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


