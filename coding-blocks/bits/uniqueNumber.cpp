#include<bits/stdc++.h>
using namespace std;

/*
logic:
     if we do XOR on series --> 5 ^ 2 ^ 5
     then 5 ^ 5 --> gives zero and x ^ 0 --> gives x
     because XOR with itself will result in Zero and any number XOR with 0 will produce same number
*/

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        ans = ans ^ num;
    }
    cout << "Unique number is " << ans << endl;
    return 0;
}