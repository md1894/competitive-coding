/*
Crossword Problem
Send Feedback
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <bits/stdc++.h>
using namespace std;
//#define N 10

bool canInsertVertical(string grid[10], int row, int col, string word){
    for(int i = 0; i < word.length(); i++){
        if(grid[row+i][col] != '-' && grid[row+i][col] != word[i])
            return false;
    }
    return true;
}


bool canInsertHorizontal(string grid[10], int row, int col, string word){
    for(int i = 0; i < word.length(); i++){
        if(grid[row][col+i] != '-' && grid[row][col+i] != word[i])
            return false;
    }
    return true;
}

void setValueHorizontally(string grid[10], int row, int col, string word, vector<bool>* helper){
    for(int i = 0; i < word.length(); i++){
        grid[row][col + i] = word[i];
        helper->at(i) = true;
    }
}

void setValueVertically(string grid[10], int row, int col, string word, vector<bool>* helper){
    for(int i = 0; i < word.length(); i++){
        grid[row+i][col] = word[i];
        helper->at(i) = true;
    }
}

void resetValueHorizontally(string grid[10], int row, int col, string word, vector<bool> helper){
    for(int i = 0; i < word.length(); i++){
        if(helper[i] == true){
            grid[row][col+i] = '-';
        }
    }
}

void resetValueVertically(string grid[10], int row, int col, string word, vector<bool> helper){
     for(int i = 0; i < word.length(); i++){
        if(helper[i] == true){
            grid[row+i][col] = '-';
        }
    }
}

bool solveCrossword(string grid[10], vector<string> wordList, int index){

    if(index == wordList.size()){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(grid[i][j] == '-' || wordList[index][0] == grid[i][j]){
                if(canInsertVertical(grid, i, j, wordList[index]) == true){
                    vector<bool> helper(10,false);
                    setValueVertically(grid, i, j, wordList[index], &helper);
                    bool ans = solveCrossword(grid, wordList, index+1);
                    if(ans == true){
                        return true;
                    }
                    resetValueVertically(grid, i, j, wordList[index], helper);
                }
                if(canInsertHorizontal(grid, i, j, wordList[index]) == true){
                    vector<bool> helper(10,false);
                    setValueHorizontally(grid, i, j, wordList[index], &helper);
                    bool ans = solveCrossword(grid, wordList, index+1);
                    if(ans == true){
                        return true;
                    }
                    resetValueHorizontally(grid, i, j, wordList[index], helper);
                }
            }
        }
    }
    return false;
}

int main(){
    string grid[10];
    for(int i = 0; i < 10; i++){
        cin >> grid[i];
    }
    string line;
    cin >> line;
    // Vector of string to save tokens 
    vector <string> listOfWords; 
    // stringstream class check1 
    stringstream check1(line); 
    string intermediate; 
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ';')) 
    { 
        listOfWords.push_back(intermediate); 
    } 
    solveCrossword(grid, listOfWords, 0);
    // cout << "grid" << endl;
    // for(int i = 0; i < 10; i++){
    //     for(int j = 0; j < 10; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    // for(int i = 0; i < listOfWords.size(); i++){
    //     cout << listOfWords[i] << endl;
    // }
    return 0;
}