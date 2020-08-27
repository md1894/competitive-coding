/*
Deepak is learning Sieve of Eratosthenes, 
He is stuck somewhere. Help him printing prime numbers.

Input Format
Single line containing integral value n.

Constraints
1<=n<=500000

Output Format
Integral value denoting nth prime number.

Sample Input
1
Sample Output
2
*/

#include<bits/stdc++.h>
using namespace std;
#define x 100000000
#define ll long long

bool isPrime[x];

void sieve(vector<ll> &primes){
	
	for(ll i=3;i<=x;i+=2){
		isPrime[i]=true;
	}

	for(ll i=3;i<=x;i+=2){
		if(isPrime[i]==true){
			for(ll j=i*i;j<=x;j+=i){
				isPrime[j]=false;
			}
		}
	}

	isPrime[2]=true;
	for(ll i=2;i<=x;i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
}

int main(){
	vector<ll> primes;
	sieve(primes);
	ll n;
	cin>>n;
	cout<<primes[n-1];
	return 0;
}
















