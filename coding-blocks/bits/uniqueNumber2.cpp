/*
We are given an array containg n numbers. 
All the numbers are present twice except for two numbers which are present only once. 
Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1

Sample Output
2 3

Explanation
Smaller number comes before larger number
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100005];
    int combinedXOR = 0;
    /*
    in this loop we have combinedXOR which contains the XOR of 2 unique numbers
    as other numbers are repeating so their values gets cancelled as XOR with same number will result
    in zero
    */
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[i] = num;
        combinedXOR = combinedXOR ^ num;
    }
    /*
    our target is to find any one number, then finding other number is very easy
    since we have the combined XOR of the number
    */
    int pos = 0;
    int temp = combinedXOR;
    /* in combinedXOR where is the first set bit */
    /* see if there is any bit that is 1 in one number, it must be 0 in the other number */
    /* so now with the help of this i will be able to find the first unique number */
    while((temp&1) != 1){
        pos++;
        temp = temp >> 1;
    }
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++){
        /* now my variable a contains one unique number */
        if((1<<pos)&arr[i]){
            a = a ^ arr[i];
        }
    }
    /* other unique number */
    b = combinedXOR ^ a;
    cout << min(a,b) << " " << max(a,b) << endl;
    return 0;
}