/*
Coder's Rating
Send Feedback
Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. 
In said contest, there are multiple types of competitions. 
Here, we consider the Open and High School competition types. 
For each type, each competitor receives a rating, an integer between 1 and 100000, inclusive. 
A coder's rating is based upon his or her level of performance in matches and is calculated 
using a complicated formula which, thankfully, you will not be asked to implement.
Although the Open and High School ratings for a coder who has participated in both competition types lately 
are usually close, this is not always the case. 
In particular, High School matches are more about speed, since many coders are able to solve all the problems, whereas Open matches require more thinking and there is a steeper curve in terms of problem difficulty.
Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. 
Each of these coders participates in both High School and Open matches. 
For each coder, you are also given an Open rating Ai and a High School rating Hi. 
Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. 
For each coder i, determine how many coders coder i is better than.
Input Format
On the first line of input is a single integer N, as described above. N lines then follow. 
Line i+1 contains two space-separated integers, Ai and Hi.
Output Format
 Line i should contain the number of coders that coder i is better than.
Sample Input
8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473
Sample Output
6
0
2
4
7
1
5
1
*/

#include<bits/stdc++.h>
using namespace std;

/*
we will build the fenwick tree of 'y' scores
we have sorted the coder array on the basis of 'x' score
so for each input in the sorted array we will query(in fenwick tree) that
how many coders are there who have 'y' component less than the current one
finally that number will decide how many coders are less than this coder score wise  
*/

class coder{
    public:
    /* because we have to display answer in same order, so this variable is used */
    int index;
    int x;
    int y;
};

bool compare(coder c1, coder c2){
    /* tie breaker */
    if(c1.x == c2.x){
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}


void update(int y, int* BIT){
    for(;y<=100000;y = y+(y&(-y))){
        BIT[y]++;
    }
}

int query(int index, int* BIT){
    int total = 0;
    for(;index>0; index = index - (index&(-index))){
        total += BIT[index];
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    coder* input = new coder[n];
    for(int i = 0; i < n; i++){
        cin >> input[i].x >> input[i].y;
        input[i].index = i;
    }
    int* BIT = new int[100001]();
    int* ans = new int[n];
    sort(input,input+n,compare);
    for(int i = 0; i < n;){
            int endIndex = i;
            /*
            if x and y scores are same for consecutive coders than answer for all of them will be the
            same that is the reason why we are counting those if exists
            first iteration of while loop will happen always.
            */
            while(endIndex < n && input[i].x == input[endIndex].x && input[i].y == input[endIndex].y){
                endIndex++;
            }
            /* first we query the data */
            for(int j = i; j < endIndex; j++){
                /* storing the result in the same order as that of input */
                ans[input[j].index] = query(input[j].y,BIT);
            }
            /* update the fenwick tree with y value of current input element */
            for(int j = i; j < endIndex; j++){
                update(input[j].y,BIT);
            }
            /* increment i */
        	i = endIndex;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    delete [] ans;
    delete [] BIT;
    delete [] input;
    return 0;
}