/*
Mike found an interesting problem. 
In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.
Input Format

First line contains number of test cases, T. Each test case contains two integers each, n and k.
Constraints

1<=T<=20 1<=n<=10^8 2<=k<=10^8
Output Format

Print the value of x for each test case.
Sample Input

2
5 2
1000 2

Sample Output

3
994

Explanation

In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, 
n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120. 
So, the answer should be 3.

*/
/*
// accepted solution
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n >> k;
        int x = INT_MAX;
        int ki=1;
        for(int i = 2; i*i <= k; i++){
            if(k%i==0){
                ki=0;
                while(k%i==0){
                    ki++;
                    k = k/i;
                }
                long long int p = i;    
                int ci = 0;
                while(p <= n){
                    ci += n/p;
                    p = p*i;
                }
                x = min(x,ci/ki);
            }
        }
        if(k > 1){
            int c = 0;
            long long int p = k;
            while(p<=n){
                c += n/p;
                p = p*k;
            }
            x = min(x,c);
        }
        if(x == INT_MAX)
            x = 0;
        cout << x << endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n,k;
    while(t--){
        cin >> n >> k;
        int x = INT_MAX;
        for(int i = 2; i*i <= k; i++){
            int ki = 0;

            if(k%i==0){
                while(k%i==0){
                    ki++;
                    k = k/i;
                }
                long long p = i;
                int ci = 0;
                while(p <= n){
                    ci += n/p;
                    p = p*i;
                }
                x = min(x,ci/ki);
            } 
        }
        if(k > 1){
            int c = 0;
            long long p = k;
            while(p<=n){
                c += n/p;
                p = p*k;
            }
            x = min(x,c);
        }
        if(x == INT_MAX)
            x = 0;
        cout << x << endl;
    }
    return 0;
}
