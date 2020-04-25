/*
Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

#include<bits/stdc++.h>
using namespace std;

int kadneAlgorithm(int input[], int n/*, int& start, int& end*/){
    int best = INT_MIN, currentSum = 0;
    /*start = 0;
    end = 0;*/
    for(int i = 0; i < n; i++){
        /*currentSum = currentSum + input[i];
        if(currentSum > best){
            best = currentSum;
            end = i;
        }
        if(currentSum <= 0){
            start = i+1 < n ? i + 1 : i;
            currentSum = 0;
        }*/
        currentSum = max(input[i], currentSum + input[i]);
        best = max(best, currentSum);
    }
    return best;
}

void initMem(int* input, int n){
    for(int i = 0; i < n; i++){
        input[i] = 0;
    }
}

int solve(int** grid, int row, int col){
    int* runningColSum = new int[col];
    int bestSum = INT_MIN;
    //int bestRectLeft = 0, bestRectRight = 0, bestRectTop = 0, bestRectBottom = 0;
    
    for(int left = 0; left < col; left++){
        for(int right = left; right < col; right++){
            for(int k = 0; k < row; k++){
                runningColSum[k] += grid[k][right];
            }

            //int top, bottom;
            int currentSum = kadneAlgorithm(runningColSum, row/*, top, bottom*/);
            if(bestSum < currentSum){
                bestSum = currentSum;
                /*bestRectLeft = left;
                bestRectRight = right;
                bestRectTop = top;
                bestRectBottom = bottom;*/
            }
        }
        initMem(runningColSum, row);
    }
    return bestSum;
}

int main(){
    // int a[] = {1, 2, -4, 4, 8, 9, -5};
    // int start, end;
    // int ans = kadneAlgorithm(a, 7, start, end);
    // cout << "Answer is " << ans << " Start is " << start << " End is " << end << endl;
    int row, col;
    cin >> row >> col;
    int** grid = new int*[row];
    for(int i = 0; i < row; i++){
        grid[i] = new int[col];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> grid[i][j];
        }
    }
    cout << solve(grid, row, col) << endl;
    return 0;
}