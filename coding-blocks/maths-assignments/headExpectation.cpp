/*
What is the expected number of coin flips for getting N consecutive heads, 
given the value of N? Say N = 1, expected number of throws to get 1 head will be 2.

Input Format
An integer n

Constraints
Output Format
An integer denoting the required answer

Sample Input
1
Sample Output
2
*/


#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << pow(2,n+1) - 2 << endl;
	return 0;
}
