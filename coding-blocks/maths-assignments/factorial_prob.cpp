#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n >> k;
        int x = INT_MAX;
        for(int i = 2; i*i <= k; i++){
            int ki = 0;

            if(k%i==0){
                while(k%i==0){
                    ki++;
                    k = k/i;
                }
                long long p = i;
                int ci = 0;
                while(p <= n){
                    ci += n/p;
                    p = p*i;
                }
                x = min(x,ci/ki);
            } 
        }
        if(k > 1){
            int c = 0;
            long long p = k;
            while(p<=n){
                c += n/p;
                p = p*k;
            }
            x = min(x,c);
        }
        if(x == INT_MAX)
            x = 0;
        cout << x << endl;
    }
    return 0;
}