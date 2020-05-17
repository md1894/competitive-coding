/*
Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/


#include<bits/stdc++.h>
using namespace std;

void buildTree(int* input, int* tree, int left, int right, int startingIndex){
    if(left == right){
        tree[startingIndex] = input[left];
        return;
    }
    int mid = (left+right)/2;
    buildTree(input,tree,left,mid,2*startingIndex);
    buildTree(input,tree,mid+1,right,2*startingIndex+1);
    tree[startingIndex] = min(tree[2*startingIndex],tree[2*startingIndex+1]);
}

void updateTree(int* input, int* tree,int start, int end,int startingIndex, int idx, int value){
    
    if(start == end){
        input[idx] = value;
        tree[startingIndex] = value;
        return;
    }
    
    int mid = (start+end)/2;
    if(idx > mid){
        updateTree(input,tree,mid+1,end,2*startingIndex+1,idx,value);
    }else{
        updateTree(input,tree,start,mid,2*startingIndex,idx,value);
    }
    tree[startingIndex] = min(tree[2*startingIndex],tree[2*startingIndex+1]);
}

int findMinInTheRange(int* tree, int start, int end, int si, int left,int right){
    //completely outside the range
    if(start > right || end < left){
        return INT_MAX;
    }
    
    //completely inside the range
    if(start >= left && end <= right){
        return tree[si];
    }
    
    // partially in the range
    int mid = (start+end)/2;
    int leftAns = findMinInTheRange(tree,start,mid,2*si,left,right);
    int rightAns = findMinInTheRange(tree,mid+1,end,2*si+1,left,right);
    return min(leftAns,rightAns);
}

int main() {
	int n,q;
    cin >> n >> q;
    int* input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int* tree = new int[4*n+1];
    buildTree(input,tree,0,n-1,1);
    while(q--){
        char type;
        cin >> type;
        if(type == 'u'){
            int x, y;
            cin >> x >> y;
            updateTree(input,tree,0,n-1,1,x-1, y);
        }else{
            int l,r;
            cin >> l >> r;
            cout << findMinInTheRange(tree,0,n-1,1,l-1,r-1) << endl;
        }
    }
    delete [] input;
    delete [] tree;
	return 0;
}