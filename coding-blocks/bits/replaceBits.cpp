#include<bits/stdc++.h>
using namespace std;

/*
suppose n is a number --> 0011 0111 --> 55
m is a number --> 0000 0101 --> 5
i --> 3 and j --> 1
your task is to fit m in n by replacing bits from 3 to 1
*/

int replaceBits(int n,int m,int i,int j){
    /* clear the bits of n from 3 to 1 */
    int a = ~0 << (i+1);
    int b = (1<<j) - 1;
    /* mask contains the value in which bits from 1 to 3 are cleared */
    int mask = a | b;
    /* cleared_n contains the modified n value in which bits 1 to 3 are cleared */
    int cleared_n = mask & n;
    /* we will shift m to j positions to fit m in the exact window i to j --> 3 to 1 */
    int shifted_m = m << j;
    return cleared_n | shifted_m;
}

int main(){
    int n,m,i,j;
    cin >> n >> m >> i >> j;
    cout << replaceBits(n,m,i,j) << endl;
    return 0;
}