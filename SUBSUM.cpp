#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void subsets(vector<ll> input, vector<ll>& sv){
	ll n = input.size();
	for(ll i = 1; i < (1<<n); i++){
		ll sum = 0;
		ll j = 0;
		for(int no = i; no > 0; j++,no = no>>1){
			if(no&1){
				sum += input[j];
			}
		}
		sv.push_back(sum);
		
	}
}

int main()
{
	ll n,a,b;
	vector<ll> v1,v2,sv1,sv2;
	cin>>n>>a>>b;
	ll n1 = n/2;
	ll n2 = n - n1;
	for(ll i = 0; i < n1; i++){
		ll num;
		cin >> num;
		v1.push_back(num);
	}
	for(ll i = 0; i < n2; i++){
		ll num;
		cin >> num;
		v2.push_back(num);
	}
	subsets(v1,sv1);
	subsets(v2,sv2);
	sort(sv2.begin(),sv2.end());
	ll ans = 0;
	for(ll i = 0; i < sv1.size(); i++){
		ll st = a - sv1[i];
		ll en = b - sv1[i];
		vector<ll>::iterator it1 = lower_bound(sv2.begin(),sv2.end(),st);
		vector<ll>::iterator it2 = upper_bound(sv2.begin(),sv2.end(),en);
		ll l = it2 - sv2.begin();
		ll k = it1 - sv2.begin();
		ans += (l-k);
	}
	for(ll i = 0; i < sv1.size(); i++){
		if(a <= sv1[i] && sv1[i] <= b){
			ans++;
		}
	}

	// including subset sums from 2nd set
        for(ll i = 0; i < sv2.size(); i++){
            if(a <= sv2[i] && sv2[i] <= b){
                ans++;
            }
        }

	// also including empty set if it lies in give range(a,b)
	if(a <= 0 && 0 <= b){
		ans++;
	}
	
    	cout<<ans<<endl;
	return 0;
}