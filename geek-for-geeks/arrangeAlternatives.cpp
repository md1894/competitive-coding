#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    cin >> n;
	    ll* arr = new ll[n];
	    for(ll i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    ll min_index = 0;
	    ll max_index = n-1;
	    /* this variable must be greater than the max-element */
        /*
        //multiplying every number by a number greater than maxEle to save
	    //it in   Dividend = Divisor * Quotient + Remainder form
	    //Dividend = number at arr[i] (stores both old and new)
	    //Divisor = maxEle +1, Quotient = new number , Remainder = old no
        */
        /*
        in this question you will have all max elements at even index and all min element at odd index
        so at odd index add min elements and at even index add max elements (two pointer)
        */
	    ll z = arr[max_index]+1;
	    for(ll i = 0; i < n; i++){
            if(i%2 != 0){
                arr[i] = arr[i] + ((arr[min_index]%z)*z);
                min_index++;
            }else{
                arr[i] = arr[i] + ((arr[max_index]%z)*z);
                max_index--;
            }
	    }
	    for(ll i = 0; i < n; i++){
	        arr[i] = arr[i]/z;
	    }
	    for(ll i = 0; i < n; i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	    delete [] arr;
	}
	return 0;
}