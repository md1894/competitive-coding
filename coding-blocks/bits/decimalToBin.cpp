#include<bits/stdc++.h>
using namespace std;

int convert(int n){
    int ans = 0;
    int p = 1;
    while(n > 0){
        int last_bit = n & 1;
        n = n >> 1;
        ans += p*last_bit;
        p = p*10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << convert(n) << endl;
    return 0;
}