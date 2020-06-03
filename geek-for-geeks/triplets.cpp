#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        int count = 0;
        for(int k = n-1; k>= 0; k--){
            int j = k - 1;
            int i = 0;
            while(j > i){
                if(arr[i]+arr[j] == arr[k]){
                    count++;
                    i++;
                    j--;
                }else if(arr[i]+arr[j] < arr[k]){
                    i++;
                }else if(arr[i]+arr[j] > arr[k]){
                    j--;
                }
            }
        }
        cout << ((count != 0) ? count : -1 )<< endl;
        delete [] arr;
    }
    return 0;
}