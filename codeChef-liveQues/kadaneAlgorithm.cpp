/*
this algorithm is used to calculate the maximum subarray possible
order n , time complexity
*/

#include<bits/stdc++.h>
using namespace std;

int kadane(int* input, int n){
    int current_sum = 0, best_sum = 0;
    for(int i = 0; i < n; i++){
        current_sum = current_sum + input[i];
        if(best_sum < current_sum){
            best_sum = current_sum;
        }
        if(current_sum  < 0){
            current_sum = 0;
        }
    }
    // cout << best_sum << endl;
    return best_sum;
}


// main is for testing purpose . if want to run and test this function
// uncomment main . and test it
// int main(){
//     int n;
//     int* input;
//     cin >> n;
//     input = new int[n];
//     for(int i = 0; i < n; i++){
//         cin >> input[i];
//     }
//     cout << kadane(input, n) << endl;
//     delete [] input;
//     return 0;
// }