#include<bits/stdc++.h>
using namespace std;

int countBits(int n){
    int ans = 0;
    /* in worst case this loop will run for 64 times(64 bit integer) */
    while(n > 0){
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}

int countBitsFast(int n){
    int ans = 0;
    /* this loop will run till the length of number in binary for example 13 --> 1101 (4) */
    while(n > 0){
        n = (n-1) & n;
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << countBits(n) << endl;
    cout << countBitsFast(n) << endl;
    return 0;
}