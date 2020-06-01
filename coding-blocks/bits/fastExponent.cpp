#include<bits/stdc++.h>
using namespace std;


/* we are taking m and breaking it */
/* dry run for 3 raise to 5 */
int fast_expo(int n, int m){
    int ans = 1;
    while(m > 0){
        /* if last bit of m is set */
        if(m&1){
            ans = ans*n;
        }
        /* increment n by squaring it */
        /* log n time complexity */
        n = n*n;
        m = m >> 1;
    }
    return ans;
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << fast_expo(n,m) << endl;
    return 0;
}