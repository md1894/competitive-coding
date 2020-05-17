/*
Connected horses
Send Feedback
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<long long int> fact(1000001);

void factModM()
{
    fact[0] = 1;
    for(int i = 1; i <= 1000001; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

bool isValid(int x,int y,int n,int m)
{
    if( x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else
        return false;
}

int dfs(int** board, int n, int m, int x, int y, bool** visited){
    int x_move[] = {2,2,-2,-2,1,1,-1,-1};
    int y_move[] = {-1,1,1,-1,2,-2,2,-2};
    visited[x][y] = true;
    int ans = 1;
    for(int i = 0; i < 8; i++){
        int next_x = x_move[i] + x;
        int next_y = y_move[i] + y;
        if(isValid(next_x,next_y,n,m) && visited[next_x][next_y] == false && board[next_x][next_y] == 1){
            ans = ans + dfs(board,n,m,next_x,next_y,visited);
        }
    }
    return ans;
}

long long possiblePermutations(int** board, int n, int m){
    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++){
            visited[i][j] = false;
        }
    }

    vector<int> componentsSize;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == false && board[i][j] == 1){
                componentsSize.push_back(dfs(board,n,m,i,j,visited));
            }
        }
    }
    long long ans = 1;
    for(int i = 0; i < componentsSize.size(); i++){
        int size = componentsSize[i];
         ans = ( (ans%MOD) * (fact[size]) % MOD)%MOD;
    }
    for(int i = 0; i < n; i++){
        delete [] visited[i];
    }
    delete [] visited;
    return ans;
}


int main(){
    factModM();
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        int** board = new int*[n];
        for(int i = 0; i < n; i++){
            board[i] = new int[m];
            for(int j = 0; j < m; j++){
                board[i][j] = 0;
            }
        }
        for(int i = 0; i < q; i++){
            int x, y;
            cin >> x >> y;
            board[x-1][y-1] = 1;
        }
        cout << possiblePermutations(board,n,m) << endl;
        for(int i = 0; i < n; i++){
            delete [] board[i];
        }
        delete [] board;
    }
    return 0;
}