#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastModExp(ll a,ll b,ll m){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}

int main(){
    cout << fastModExp(15,150,1089) << endl;
    return 0;
}