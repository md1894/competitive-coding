/*
Murder
Send Feedback
Once detective Saikat was solving a murder case. 
While going to the crime scene he took the stairs and saw that a number is written on every stair. 
He found it suspicious and decides to remember all the numbers that he has seen till now. 
While remembering the numbers he found that he can find some pattern in those numbers. 
So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include<bits/stdc++.h>
using namespace std;

long merge(long input[], long left, long mid, long right){
    long i = left, j = mid+1, k = 0, ans = 0;
    long temp[right-left+1];
    while(i <= mid && j <= right){
        if(input[i] < input[j]){
            ans += input[i]*(right-(j-1));
            temp[k++] = input[i++];
        }else{
            temp[k++] = input[j++];
        }
    }
    while(i <= mid){
        temp[k++] = input[i++];
    }
    while(j <= right){
        temp[k++] = input[j++];
    }
    for(long k = 0, i = left; i <= right; i++, k++){
        input[i] = temp[k];
    }
    return ans;
}


long murder(long input[], long left, long right){
    long ans = 0;
    // cout << "murder(input, left, right)" << endl;
    // cout << "left = " << left << endl;
    // cout << "right = " << right << endl;
    // for(long i = left; i <= right; i++){
    //     cout << input[i] << " ";
    // }
    // cout << endl;
    if(left < right){
        long mid = (left + right)/2;
        long leftAns = murder(input, left, mid);
        long rightAns = murder(input, mid+1, right);
        long mergeAns = merge(input, left, mid, right);
        ans = leftAns + rightAns + mergeAns;
    }
    return ans;
}


long murder(long input[], long n){
    return murder(input, 0, n-1);
}


int main() {
	int t;
    cin >> t;
    while(t--){
        long n;
        cin >> n;
        long input[n];
        for(long i = 0; i < n; i++){
            cin >> input[i];
        }
        cout << murder(input, n) << endl;
    }
    return 0;
}
