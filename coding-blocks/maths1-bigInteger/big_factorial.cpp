#include<bits/stdc++.h>
using namespace std;

/* dry run this for 6! or 7! */
/* multiplication is done that too in the opposite direction */

void multiply(int* arr, int& n, int num){
  int carry = 0;
  for(int i = 0; i < n; i++){
    int product = arr[i]*num + carry;
    arr[i] = product % 10;
    carry = product / 10; 
  }
  while(carry){
    arr[n] = carry % 10;
    carry = carry / 10;
    n++;
  }
}

void big_factorial(int no){
  int* arr = new int[1000];
  for(int i = 0; i < 1000; i++){
    arr[i] = 0;
  }
  arr[0] = 1;
  int n = 1;
  for(int i = 2; i <= no; i++){
     multiply(arr,n,i);
  }
  for(int i = n-1; i >= 0; i--){
    cout << arr[i];
  }
  cout << endl;
  delete [] arr;
}

int main(){
  int n;
  cin >> n;
  big_factorial(n);
  return 0;
}