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

#include <bits/stdc++.h>
#define N 100000
using namespace std;
typedef long long int ll;

// void seive(int *p, vector<int>& primes){
// 	p[0] = p[1] = 0;
// 	p[2] = 1;
// 	primes.push_back(2);
// 	for(ll i = 3; i <= N; i += 2){
// 		p[i] = 1;
// 	}
// 	for(ll i = 3; i <= N; i += 2){
// 		if(p[i] == 1){
// 			primes.push_back(i);
// 			for(ll j = i*i; j <= N; j += i){
// 				p [j] = 0;
// 			}
// 		}
// 	}
// }

// void do_prime_factorization(vector<int>& primes,
// 	ll m, vector<pair<int, pair<int, int>>>& ans)
// {
// 	ll factor;
// 	int count;
// 	for(int i = 0; primes[i]*primes[i] <= m; i++){
// 		if(m % primes[i] == 0){
// 			count = 0;
// 			factor = 1;
// 			while(m % primes[i] == 0){
// 				count++;
// 				factor = factor*primes[i];
// 				m = m / primes[i];
// 			}
// 			ans.push_back(make_pair(factor, make_pair(primes[i], count)));
// 		}
// 	}
// 	if(m != 1){
// 		ans.push_back(make_pair(m, make_pair(m, 1)));
// 	}
// }

// int main(){
// 	int p[N+1] = {0};
// 	vector<int> primes;
// 	seive(p, primes);
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		vector<pair <int, pair<int, int> > >  ans;
// 		ll m;
// 		cin >> m;
// 		do_prime_factorization(primes, m, ans);
// 		if(ans.size() == 1 && ans[0].second.second >= 6){
// 			ll one = ans[0].second.first;
// 			ll two = one*one;
// 			ll three = ans[0].first/(one*two);
// 			// success
// 			cout << "YES" << endl;
// 			cout << one << " " << two << " " << three << endl;
// 		}else if(ans.size() == 2){
// 			ll one = ans[0].second.first;
// 			ll two = ans[1].second.first;
// 			ll gen = m/(one*two);
// 			if(gen != ans[0].first && gen != ans[1].first && gen >= 2){
// 				// success
// 				cout << "YES" << endl;
// 				cout << one << " " << two << " " << gen << endl;
// 			}else{
// 				// fail
// 				cout << "NO" << endl;
// 			}
// 		}else if(ans.size() >= 3){
// 			ll one = ans[0].first;
// 			ll two = ans[1].first;
// 			ll three = m/(one*two);
// 			//success
// 			cout << "YES" << endl;
// 			cout << one << " " << two << " " << three << endl;
// 		}else{
// 			cout << "NO" << endl;
// 		}
// 	}
// 	return 0;
// }

// above approach is by using prime seive
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll m;
		ll counter = 0;
		vector<ll> arr;
		cin >> m;
		for (ll i = 1; i * i <= m; i++)
		{
			if (m % i == 0)
			{
				counter++;
				m = m / i;
				arr.push_back(i);
			}
			if (counter == 2)
			{
				arr.push_back(m);
				break;
			}
		}
		if (counter < 2)
		{
			cout << "NO" << endl;
		}
		else if (arr[0] == arr[2] || arr[1] == arr[2])
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
		}
	}
	return 0;
}
