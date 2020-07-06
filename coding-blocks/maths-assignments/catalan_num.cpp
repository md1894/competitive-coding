#include<iostream>
using namespace std;

// A recursive function to find nth catalan number 
unsigned long int catalan(unsigned int n) 
{ 
    // Base case 
    if (n <= 1) return 1; 
  
    // catalan(n) is sum of catalan(i)*catalan(n-i-1) 
    unsigned long int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return res; 
}


//DP approach
unsigned long int catalanDP(unsigned int n) 
{ 
    // Table to store results of subproblems 
    unsigned long int catalan[n+1]; 
  
    // Initialize first two values in table 
    catalan[0] = catalan[1] = 1; 
  
    // Fill entries in catalan[] using recursive formula 
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    // Return last entry 
    return catalan[n]; 
}


int main() {
	int n;
	cin >> n;
	cout << catalanDP(n) << endl;
	return 0;
}