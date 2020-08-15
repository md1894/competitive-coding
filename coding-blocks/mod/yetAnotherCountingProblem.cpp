/*

C. Yet Another Counting Problem

You are given two integers a and b, and q queries. 
The i-th query consists of two numbers li and ri, 
and the answer to it is the number of integers x such that li ≤ x ≤ ri, and ((x % a) % b) != ((x % b) % a).
Calculate the answer for each query.

Recall that y % z
is the remainder of the division of y by z. For example, 5 % 3=2, 7 % 8=7, 9 % 4=1, 9 % 9=0.

Input
The first line contains one integer t
(1 ≤ t ≤ 100) — the number of test cases. 
Then the test cases follow.

The first line of each test case contains three integers 
a, b and q (1 ≤ a,b ≤ 200; 1 ≤ q ≤ 500).
Then q lines follow, each containing two integers li and ri (1 ≤ li ≤ ri ≤ 10^18) 
for the corresponding query.

Output

For each test case, print q
integers — the answers to the queries of this test case in the order they appear.

Example

Input
2
4 6 5
1 1
1 3
1 5
1 7
1 9
7 10 2
7 8
100 200

Output
0 0 0 2 4 
0 91 

*/



#include<bits/stdc++.h>
using namespace std;
#define N 40000

typedef long long int ll;
int a, b;
int arr [N+1];
int sum [N+1];


// pre computed the array and sum
void construct_array(){

    for(int x = 0; x <= (a*b); x++)
        if(((x % a) % b) != ((x % b) % a))
            arr [x] = 1;
        else
            arr [x] = 0;
        

    sum [0] = 0;
    for(int x = 1; x <= (a*b); x++)
        if(arr [x])
            sum [x] = sum [x-1] + 1;
        else
            sum [x] = sum [x-1];
}

ll solve(ll n){
    /*
    numbers will get repeated in a cycle
    0   to  ab-1
    ab  to 2ab-1
    2ab to 3ab-1
    ...
    ...
    and so on
    */
    ll ans = n/(a*b)*sum[((a*b)-1)];
    ans += sum[n%(a*b)];
    return ans;
}

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int q;
        cin >> a >> b >> q;
        // construct array of sums of size AxB
        construct_array();
        while(q--){
            ll li, ri;
            cin >> li >> ri;
            cout << solve(ri) - solve(li-1) << " ";
        }
        cout << endl;
    }
    return 0;
}

















