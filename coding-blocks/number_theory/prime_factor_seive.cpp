#include<bits/stdc++.h>
using namespace std;

/*
this approach will be useful if there are a lot of queries
so with the help of pre computed seive we already have vector of primes in hand
so we just have to iterate through primes instead of composite numbers
*/
vector<int> seive(int *p, int n){
	p[0] = p[1] = 1;
	vector<int> primes;
	for(int i = 2; i <= n; i++){
		if(p[i] == 0){
			primes.push_back(i);
			for(int j = i*i; j <= n; j += i){
				p[j] = 1;
			}
		}
	}
	return primes;
}

void print_prime_fact(vector<int>& primes, int m){
	vector<int> prime_factors;
	int number_of_factors = 1;
	int count;
	for(int i = 0; primes[i]*primes[i] <= m; i++){
		if(m % primes[i] == 0){
			prime_factors.push_back(primes[i]);
			count = 0;
			while(m % primes[i] == 0){
				count++;
				m = m / primes[i];
			}
			number_of_factors = number_of_factors*(count+1);
		}
	}
	if(m != 1){
		prime_factors.push_back(m);
		number_of_factors = 2*number_of_factors;
	}
	for(int i = 0; i < prime_factors.size(); i++){
		cout << prime_factors[i] << " ";
	}
	cout << endl;
	cout << "No Of Factors is " << number_of_factors << endl;
}

int main(){
	int p[10001] = {0};
	vector<int> primes = seive(p, 10000);
	int q;
	cin >> q;
	while(q--){
		int m;
		cin >> m;
		// find prime factors and number of factors
		print_prime_fact(primes, m);
	}
	return 0;
}