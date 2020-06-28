/*
find out number of numbers in 1 to n
that are divisible by any of the prime numbers less than 20
*/

/*
demo test case :
5
5
10
12
15
18

4
9
11
14
17
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int primes[] = {2,3,5,7,11,13,17,19};
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        /* total number of subsets */
        ll subsets = (1<<8)-1;
        /* iterating over all the subsets */
        for(ll i = 1; i <= subsets; i++){
            ll deno = 1ll;
            ll setBits = __builtin_popcount(i);
            for(int j = 0; j < 8; j++){
                /* if the bit is set , it will contribute in our denominator */
                if(i & (1<<j)){
                    deno *= primes[j];
                }
            }
            /* if set bits are odd then add else substract */
            if(setBits & 1){
                ans += n/deno;
            }else{
                ans -= n/deno;
            }
        }
        cout << ans << endl;
    }
    return 0;
}