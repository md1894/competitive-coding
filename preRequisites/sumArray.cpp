/*
Sum Array
Send Feedback
Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
Constraints:
1<=n<=100
Output:
Print a single integer denoting the sum.
Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, sum = 0;
    cin >> n;
    int** input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> input[i][j];
            if(i == 0 || i == n-1 || j == 0 || j == n-1)
                sum += input[i][j];
        }
    }
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(i == j){
                if(j == n-1-j){
                    sum += input[i][j];
                }else{
                    sum += input[i][j] + input[i][n-1-j];
                }
            }
        }
    }
    cout<<sum;
	return 0;
}
