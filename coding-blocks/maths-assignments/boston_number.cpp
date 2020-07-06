/*
A Boston number is a composite number, 
the sum of whose digits is the sum of the digits of its prime factors obtained as a result of 
prime factorization (excluding 1 ). The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 . 
For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7. 
Write a program to check whether a given integer is a Boston number.

Input Format
There will be only one line of input:N , the number which needs to be checked.

Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.

Sample Input
378
Sample Output
1
Explanation
Self Explanatory
*/

#include<bits/stdc++.h>
using namespace std;

int calc_digit_sum(int);

int calc_prime_sum(int n) {
    int sum = 0;
    int n_ = n;
    // accomodate total number of 2's
    while(n%2==0){
        sum += 2;
        n = n/2;
    }
    //main loop
    for(int i = 3; i <= sqrt(n); i += 2){
        while(n%i==0){
            if(i > 9){
                n_ = calc_digit_sum(i);
                sum += n_;
            }else
                sum += i;
            n = n/i;
        }
    }
    if(n>2){
        sum += n > 9 ? calc_digit_sum(n): n;
    }
    return sum;
}

int calc_digit_sum(int n){
    int sum = 0;
    while(n != 0){
        sum += n%10;
        n = n / 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    // cout << calc_digit_sum(n) <<" "<< calc_prime_sum(n)<<endl;
    if(calc_digit_sum(n) == calc_prime_sum(n))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}