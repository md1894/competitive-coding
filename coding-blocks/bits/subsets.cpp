#include<bits/stdc++.h>
using namespace std;

/* dry run for abc */
void extract_subset(int n, char a[]){
    int pos = 0;
    while(n > 0){
        int last_bit = n & 1;
        if(last_bit == 1){
            cout << a[pos];
        }
        pos++;
        n = n >> 1;
    }
    cout << endl;
}

void print_subsets(char a[]){
    int n = strlen(a);
    /* there will be 2^n subsets including the empty set */
    for(int i = 0; i < (1<<n); i++){
        /* each number from 0 to 2^n-1 will correspond to a subset */
        /* for i == 5 --> 101 --> a[2],a[0] */
        extract_subset(i,a);
    }
}

int main(){
    char a[100];
    cin >> a;
    print_subsets(a);
    return 0;
}