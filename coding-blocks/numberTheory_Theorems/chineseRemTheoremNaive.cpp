#include<bits/stdc++.h>
using namespace std;


int findX(int num[], int rem[], int k){
    int x = 1;
    /*
    according to chinese remainder theorem
    this loop has to break
    there will be atleast one x
    */
    while(1){
        int j;

        for(j=0; j < k; j++){

            if(x%num[j] != rem[j]){
                break;
            }
        }

        // if all conditions satisfied , it means we have
        // found our x, j loop
        if(j == k)
            return x;
        
        // else increment x
        x++;
    }
    
    return x;
}

int main(){
    int num[] = {3,4,5};
    int rem[] = {2,3,1};
    int k = sizeof(num)/sizeof(int);
    cout << findX(num, rem, k) << endl;
    return 0;
}