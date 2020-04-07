/*
given an array that contains positive numbers and negative numbers
figure out max possible product possible from contigous subarray
*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(int* input, int n){
    int best = 0,maxPositive = 1, maxNegative = 1;
    for(int i = 0; i < n; i++){
        if(input[i] == 0){
            maxPositive = 1;
            maxNegative = 1;
        }else if(input[i] > 0){
            maxPositive = maxPositive*input[i];
            maxNegative = min(maxNegative*input[i], 1);
        }else{
            int temp = maxPositive;
            maxPositive = max(maxNegative*input[i],1);
            maxNegative = temp*input[i];
        }
        if(best < maxPositive){
            best = maxPositive;
        }
    }
    return best;
}

int main(){
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    cout << maxProduct(input, n) << endl;
    delete [] input;
}