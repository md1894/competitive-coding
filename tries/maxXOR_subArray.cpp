/*
Maximum XOR Subarray
Send Feedback
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* right;
    TrieNode* left;

    TrieNode(){
        this->right = NULL;
        this->left = NULL;
    }
};

void insert(TrieNode* head, int n){
    TrieNode* current = head;
    for(int i = 31; i >= 0; i--){
        /* we will check the bit from 31 to 0 */
        /* 0 or 1 */
        int currentBit = (n>>i)&1;
        if(currentBit == 0){
            /* if currentBit is Zero then we have to goto left */
            if(current->left == NULL){
                current->left = new TrieNode();
            }
            current = current->left;
        }else{
            /* if currentBit is One then we have to goto right */
            if(current->right == NULL){
                current->right = new TrieNode();
            }
            current = current->right;
        }
    }
}


/* in this function we will maximize the XOR with n in the trie and return it */
int query(TrieNode* head, int n){
    TrieNode* currentNode = head;
    int value = 0;
    for(int i = 31 ; i >= 0; i--){
        int currentBit = (n>>i) & 1;
        if(currentBit == 0){
            if(currentNode->right != NULL){
                value += pow(2,i);
                currentNode = currentNode->right;
            }else{
                currentNode = currentNode->left;
            }
        }else{
            if(currentNode->left){
                value += pow(2,i);
                currentNode = currentNode->left;
            }else{
                currentNode = currentNode->right;
            }
        }
    }
    return value;
}

int max_XOR_subarray(int input[], int n){
    TrieNode* head = new TrieNode();
    /* this variable will keep the track of overall maximum in the array */
    int result = INT_MIN;
    /* this variable will hold the combined XOR value as we move forward */
    int prev_xor = 0;
    for(int i = 0; i < n; i++){
        prev_xor = prev_xor ^ input[i];
        insert(head,prev_xor);
        result = max(result,query(head,prev_xor));
    }
    return result;
}

int main(){
     int a[] = {8,1,2,12,7,6};
    //int a[] = {1,2,8,12};
    cout << max_XOR_subarray(a,6) << endl;
    return 0;
}