/*
MISERMAN - Wise And Miser
#dynamic-programming
Jack is a wise and miser man. Always tries to save his money.

One day, he wants to go from city A to city B. Between A and B, 
there are N number of cities(including B and excluding A) and in each city there are M buses 
numbered from 1 to M. And the fare of each bus is different. 
Means for all N*M busses, fare (K) may be different or same. 
Now Jack has to go from city A to city B following these conditions:

At every city, he has to change the bus.

And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.

You are to help Jack to go from A to B by spending the minimum amount of money.

N, M, K <= 100.

Input
Line 1:    N M
Line 2-:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.

Output
Single Line containing the minimum amount of fare that Jack has to give.

Example
Input:
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9

Output:
10
Explanation
1 -> 4 -> 1 -> 3 -> 1: 10
*/

#include <bits/stdc++.h>
using namespace std;

int calculateFare(int** input, int n, int m, int row, int col){
    if(col < 1 || col > m){
        return INT_MAX;
    }
    if(row == n-1){
        return input[row][col];
    }
    int option1 = calculateFare(input,n,m,row+1,col);

    if(option1 != INT_MAX)
        option1 += input[row][col];
    
    int option2 = calculateFare(input,n,m,row+1,col-1);

    if(option2 != INT_MAX)
        option2 += input[row][col];
    
    int option3 = calculateFare(input,n,m,row+1,col+1);

    if(option3 != INT_MAX)
        option3 += input[row][col];
    
    return min(option1, min(option2,option3));
}

int miserMan(int** input, int n, int m){
    int best = INT_MAX;
    /* this loop will make that man choose each bus and calculate the fare */
    /* whichever fare will be minimum that will be choosen as our answer */
    for(int i = 1; i <= m; i++){
        int ans = calculateFare(input, n, m, 0, i);
        if(ans < best){
            best = ans;
        }
    }
    return best;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int** input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[m+1];
        input[i][0] = INT_MAX;
        for(int j = 1; j <= m; j++){
            cin >> input[i][j];
        }
    }
    cout << miserMan(input, n, m) << endl;
    for(int i = 0; i < n; i++){
        delete [] input[i];
    }
    delete [] input;
    return 0;
}
