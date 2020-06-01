#include<bits/stdc++.h>
using namespace std;

/*
~0 --> 1111111
~0 << 2 --> 1111100 --> mask
*/
int clearLastI(int num,int i){
    int mask = ~0<<i;
    return num & mask;
}


/*
31 ->> 0001 1111
lets say we want to clear bits from 1 to 3 inclusive
i == 3, j == 1
mask --> 0001 0001
*/
int clear_in_middle_bits(int num, int i, int j){
    /* we will break the mask into 2 parts and then or those part to get the final mask */
    int a = ~0 << (i+1);
    int b = (1<<j)-1;
    int mask = a | b;
    return num & mask;
}

int main(){
    int num;
    cin >> num;
    int i;
    cin >> i;
    cout << "After clearing last " << i << " bits " << clearLastI(num,i) << endl;
    int j;
    cin >> num >> i >> j;
    cout << clear_in_middle_bits(num,i,j) << endl;
    return 0;
}