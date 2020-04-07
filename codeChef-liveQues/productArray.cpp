/*
given an array of integers
you have to create a product array which contains
product of all element except the current element
without using extra space and division operator in order n time complexity
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* input = new int[n];
    int* product = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    // i will calculate the left product and fill that in the product
    // array
    int lp = 1;
    for(int i = 0; i < n; i++){
        product[i] = lp;
        lp = lp*input[i];
    }
    // product = leftProduct * rightProduct;
    int rp = 1;
    for(int i = n-1; i >= 0; i--){
        product[i] = rp*product[i];
        rp = rp*input[i];
    }

    for(int i = 0; i < n; i++){
        cout << product[i] << " ";
    }
    cout << endl;
    return 0;
}