/*
Hänschen dreams he is in a shop with an infinite amount of marbles. 
He is allowed to select n marbles. There are marbles of k different colors. 
From each color, there are also infinitely many marbles. 
Hänschen wants to have at least one marble of each color, 
but still there are a lot of possibilities for his selection. 
In his effort to make a decision he wakes up. 
Now he asks you how many possibilities for his selection he would have had. 
Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.

Input Format
The first line of input contains a number 'T' that indicates the number of test cases to follow. 
Each test case consists of one line containing n and k, 
where n is the number of marbles Hänschen selects and k is the number of different colors of the marbles.

Constraints
1<=T<=100
1<=k<=n<=1000000

Output Format
For each test case print the number of possibilities that Hänschen would have had. 
You can assume that this number exceeds the limit of a signed 64-bit integer.

Sample Input
2
10 10
30 7
Sample Output
1
475020
*/

// C++ implementation to find nCr 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find the nCr 
long long nCr(long long n, long long r) 
{ 

	// p holds the value of n*(n-1)*(n-2)..., 
	// k holds the value of r*(r-1)... 
	long long p = 1, k = 1; 

	// C(n, r) == C(n, n-r), 
	// choosing the smaller value 
	if (n - r < r) 
		r = n - r; 

	if (r != 0) { 
		while (r) { 
			p *= n; 
			k *= r; 

			// gcd of p, k 
			long long m = __gcd(p, k); 

			// dividing by gcd, to simplify product 
			// division by their gcd saves from the overflow 
			p /= m; 
			k /= m; 

			n--; 
			r--; 
		} 

		// k should be simplified to 1 
		// as C(n, r) is a natural number 
		// (denominator should be 1 ) . 
	} 

	else
		p = 1; 

	// if our approach is correct p = ans and k =1 
	return p;
} 




int main(){
	long long t;
	cin >> t;
	while(t--){
		long long n,k;
		cin >> n >> k;
		cout << nCr(n-1,k-1)<<endl;
	}
	return 0;
}