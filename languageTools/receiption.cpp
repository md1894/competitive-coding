#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	int* dept = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		cin >> dept[i];
	}
	sort(arr, arr+n);
	sort(dept, dept+n);
	int ai = 0, di = 0, best = 0, count = 0;
	while(ai < n){
		while(arr[ai] >= dept[di]){
			count--;
			di++;
		}

		if(arr[ai] < dept[di]){
			count++;
			ai++;
		}
		if(count > best){
			best = count;
		}
	}
	cout << best << endl;
	return 0;
}
