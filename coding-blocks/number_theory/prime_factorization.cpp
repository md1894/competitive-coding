#include<bits/stdc++.h>
using namespace std;

void print_prime_factors(int n){
	// vector of pairs, store (prime_factor, count)
	vector<pair<int,int> > primes;
	int cnt;
	// for a number n, if there is no prime factor less than equalt to sqrt(n)
	// then there will be no prime factor greater than equal to sqrt(n)
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			cnt = 0;
			while(n % i == 0){
				cnt++;
				n = n / i;
			}
			primes.push_back(make_pair(i, cnt));
		}
	}
	// take example of 66, i.e. n=66
	// at the end if n != 1, means any other number then that number is also a
	// prime factor
	if(n != 1){
		primes.push_back(make_pair(n,1));
	}
	for(int i = 0; i < primes.size(); i++){
		cout << primes[i].first << "^" << primes[i].second << endl;
	}
}

int main(){
	int n;
	cin >> n;
	print_prime_factors(n);
	return 0;
}