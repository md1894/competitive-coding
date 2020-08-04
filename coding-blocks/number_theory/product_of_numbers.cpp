/*
You are given one integer number n. 
Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n or 
say that it is impossible to do it.

If there are several answers, you can print any.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤100) — 
the number of test cases.

The next n lines describe test cases. 
The i-th test case is given on a new line as one integer n (2≤n≤10^9).

Output
For each test case, print the answer on it. 
Print "NO" if it is impossible to represent n as a⋅b⋅c for 
some distinct integers a,b,c such that 2≤a,b,c.

Otherwise, print "YES" and any possible such representation.

Example
inputCopy
5
64
32
97
2
12345
outputCopy
YES
2 4 8 
NO
NO
NO
YES
3 5 823 
*/


#include<bits/stdc++.h>
#define N 100000
using namespace std;
typedef long long int ll;


void seive(int *p, vector<int>& primes){
	p[0] = p[1] = 0;
	p[2] = 1;
	primes.push_back(i);
	for(ll i = 3; i <= N; i += 2){
		p[i] = 1;
	}
	for(ll i = 3; i <= N; i += 2){
		if(p[i] == 1){
			primes.push_back(i);
			for(ll j = i*i; j <= N; j += i){
				p [j] = 0;
			}
		}
	}
}

vector<int> do_prime_factorization(vector<int>& primes, 
	ll m, vector<int>& ans)
{
	int count;
	vector<pair<int,int>> prime_factors;
	for(ll i = 0; primes[i]*primes[i] <= m; i++){
		if(m % primes[i] == 0){
			count = 0;
			while(m % primes[i] == 0){
				count++;
				m = m / primes[i];
			}
			primes.push_back(make_pair(primes[i], count));
		}
	}
	if(m != 1){
		prime_factors.push_back(make_pair(m, 1));
	}
}

int main(){
	int p[N+1] = {0};
	vector<int> primes;
	seive(p, primes);
	int t;
	cin >> t;
	while(t--){
		ll m;
		cin >> m;
		vector<int> ans;
		do_prime_factorization(primes, m, ans);
		if(ans.empty() || (ans.size() == 1 && ans[0].second < 6)){
			cout << "NO" << endl;
		}else if (ans.size() == 2){
			ll generatedNumber = (m)/(ans[0]*ans[1]);
			bool isValid = generatedNumber == ans[0] || generatedNumber == ans[1];
			if(generatedNumber >= 2 && isValid){
				cout << "YES" << endl;
				cout << ans[0] << " " << ans[1] << " " << generatedNumber << endl;
			}else{
				cout << "NO" << endl;
			}
		}else{
			
		}
	}
	return 0;
}








