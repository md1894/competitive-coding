#include<iostream>
using namespace std;

int flipBit(int n, int i){
    int mask = (1 << i) ^ n;
    return mask;
}

int main(){
    int n, i;
    cin >> n >> i;
    cout << flipBit(n,i) << endl;
    return 0;
}