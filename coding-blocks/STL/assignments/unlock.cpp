/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. 
He is given a number N and a number K. And he is also given permutation of first N natural numbers . 
The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. 
Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. 
The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5

Sample Output
5 4 3 2 1

Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void unlock(vector<int>& input, LL k){
    /* this will always give me the maximum element for that position */
    priority_queue<int> pq;
    /* it will keep the mapping of value with its changing index */
    unordered_map<int,int> index_map;
    for(int i = 0; i < input.size(); i++){
        pq.push(input[i]);
        index_map[input[i]] = i;
    }
    LL swaps = 0;
    for(int i = 0; i < input.size(); i++){
        if(swaps == k)
            break;
        
        int largest = pq.top();
        if(input[i] < largest){
            /* getting the index of the largest value currently in the max heap */
            int index = index_map[largest];
            /* update the index_map */
            index_map[largest] = i;
            index_map[input[i]] = index;
            swap(input[i],input[index]);
            swaps++;
        }
        /* now remove the largest value, as this place(i) now contains the largest value */
        pq.pop();
    }
    for(auto i: input){
        cout << i << " ";
    }
}

int main(){
    int n;
    LL k;
    cin >> n >> k;
    vector<int> input;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    unlock(input,k);
    return 0;
}