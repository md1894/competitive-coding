/*
you are given N elements find the number of good subarrays,
a good suarrays is a sub array such that (a[i]+a[i+1]+____+a[j]) is divisible by N
1<=T<=10
1<=N<=10^5
|a[i]|<=10^9

sample test case:
1
5
1 3 2 6 4
3
*/

#include<bits/stdc++.h>
#include<cstring>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int freq[1000001];
        cin >> n;
        memset(freq,0,sizeof(freq));
        freq[0] = 1;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            sum += num;
            /*
            calculate your sum as this, since sum can be large negative number 
            so adding just n won’t make it positive so first take modulo then adding n will make it positive.
            */
			sum %= n;
            sum = (sum+n)%n;
            freq[sum]++;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll m = freq[i];
            ans += (m)*(m-1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}