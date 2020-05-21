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

int maxXOR_pair(int input[], int n, TrieNode* head){
    /* this variable will keep the track of total max xor in whole array */
    int max_xor = INT_MIN;
    for(int i = 0; i < n; i++){
        /* this variable will have a value of max xor that will be obtained from input[i] */
        int current_max_xor = 0;
        /* for each value we have to traverse the tree starting from head node */
        TrieNode* currentNode = head;
        for(int j = 31; j >= 0; j--){
            /* calculate the current bit, weather it is zero or one */
            int currentBit = (input[i] >> j) & 1;
            if(currentBit == 0){
                /* if the currentBit is 0, to get 1 in XOR we must have a 1*/
                /* our target is to get the maximum 1's */
                if(currentNode->right != NULL){
                    /* here we will get a 1, so we must increment the answer */
                    current_max_xor += pow(2,j);
                    currentNode = currentNode->right;
                }else{
                    /* if one is not available then go to left */
                    currentNode = currentNode->left;
                }
            }else{
                if(currentNode->left != NULL){
                    /* here we will get a 1, so we must increment the answer */
                    current_max_xor += pow(2,j);
                    currentNode = currentNode->left;
                }else{
                    currentNode = currentNode->right;
                }
            }
        }
        /* if the XOR value obtained from input[i] is max or not*/
        if(current_max_xor > max_xor){
            max_xor = current_max_xor;
        }
    }
    return max_xor;
}

int main(){
    int a[] = {2,6,10,5,8};
    TrieNode* head = new TrieNode();
    for(int i = 0; i < 5; i++){
        insert(head,a[i]);
    }
    cout << maxXOR_pair(a,5,head) << endl;
    delete head;
    return 0;
}