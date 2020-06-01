/*
We are given an array containg n numbers. 
All the numbers are present thrice except for one number which is only present once. 
Find the unique number. Only use - bitwise operators, and no extra space.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3

Sample Output
3

Explanation
3 is present only once
*/

#include<bits/stdc++.h>
using namespace std;


/*
to solve this problem we have used the logic of count of bits
since there are 3N+1 total numbers
so we will consider that bits which appear 3N+1 times and there by constructing our unique number
*/
int main(){
    int n;
    cin >> n;
    int cnt[64] = {0};
    for(int i = 0; i < n; i++){
        int no;
        cin >> no;
        /* to store the bits of current number */
        for(int j = 0; j < 64; j++){
            cnt[j] += no & 1;
            no = no >> 1;
        }
    }
    int p = 1;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cnt[i] = cnt[i]%3;
        /* if remainder is 1 then only that bit will contribute in our number */
        ans = ans + cnt[i]*(p);
        p = p << 1;
    }
    cout << ans << endl;
    return 0;
}