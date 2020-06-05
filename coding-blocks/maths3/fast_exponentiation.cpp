#include<bits/stdc++.h>
using namespace std;


int fast_power(int a, int n){
	if(n == 0){
		return 1;
	}
	/* breaking the problem into halfs */
	int subProblem = fast_power(a,n/2);
	/* if n is odd */
	if(n&1){
		return a*subProblem*subProblem;
	}
	/* if n is even */
	return subProblem*subProblem;
}

int main(){
	int a,n;
	cin >> a >> n;
	/* complexity will be logN */
	cout << fast_power(a,n) << endl;
	return 0;
}
