/*
Momos Market
Send Feedback
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/


#include<bits/stdc++.h>
using namespace std;


int doBSearch(long sum[], int n, long X){
    int start = 0;
    int end = n-1;
    // cout << "n = " << n << "X = " << X <<endl;
    // for(int i = 0; i < n; i++){
    //     cout << sum[i] << " " << endl;
    // }
    // cout << endl;
    while(start <= end){
        int mid = (start + end)/2;
        if(sum[mid] == X)
            return mid;
        else if(sum[mid] < X)
            start = mid+1;
        else{
            if(X > sum[mid-1] && X < sum[mid])
                return mid - 1;
            else
                end = mid - 1;
        }
    }
}

void solve(long input[], int n, long query[], int q){
    long sum[n];
    long sum_ = 0;
    for(int i = 0; i < n; i++){
        sum_ += input[i];
        sum[i] = sum_;
    }
    for(int i = 0; i < q; i++){
        long inHandMoney = query[i];
        int momosPurchased = 0;
        long moneySaved = 0;
        if(inHandMoney >= sum[0] && inHandMoney <= sum[n-1]){
            int index = doBSearch(sum, n, query[i]);
            moneySaved = inHandMoney - sum[index];
            momosPurchased = index + 1;
        }else{
            if(inHandMoney < sum[0]){
                moneySaved = inHandMoney;
                momosPurchased = 0;
            }else{
                moneySaved = inHandMoney - sum[n-1];
                momosPurchased = n;
            }
        }
        cout << momosPurchased << " " << moneySaved << endl;
    }
}

int main()
{
	int n,q;
    cin >> n;
    long input[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    cin >> q;
    long query[q];
    for(int i = 0; i < q; i++){
        cin >> query[i];
    }
    solve(input, n, query, q);
	return 0;
}

