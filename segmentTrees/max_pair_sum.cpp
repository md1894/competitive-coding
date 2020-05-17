/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). 
There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. 
Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, 
representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int maximum;
    int second_maximum;
};

void buildTree(int *arr,node *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].maximum = arr[start];
        tree[treeNode].second_maximum = INT_MIN;
        return ;
    }

    int mid = (start + end)/2;

    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode + 1);

    node left = tree[2*treeNode];
    node right = tree[2*treeNode + 1];

    tree[treeNode].maximum = max(left.maximum,right.maximum);
    tree[treeNode].second_maximum = min(max(right.second_maximum,left.maximum),max(right.maximum,left.second_maximum));
    
    return;
}

void update(int *arr,node *tree,int start,int end,int treeNode,int index,int value)
{
    if(start == end)
    {
        tree[treeNode].maximum = value;
        tree[treeNode].second_maximum = INT_MIN;
        return ;
    }
    else
    {
        int mid = (start + end)/2;
        if(index > mid)
        {
            update(arr,tree,mid+1,end,2*treeNode + 1,index,value);
        }
        else
        {
            update(arr,tree,start,mid,2*treeNode,index,value);
        }
        node left = tree[2*treeNode];
        node right = tree[2*treeNode + 1];
        
        tree[treeNode].maximum = max(left.maximum,right.maximum);
        tree[treeNode].second_maximum = min(max(right.second_maximum,left.maximum),max(right.maximum,left.second_maximum));
    
        return;
    }
}

node query(int *arr,node *tree,int start,int end,int treeNode,int left,int right)
{
    if(start > right || end < left)
    {
        node zero;
        zero.maximum = INT_MIN;
        zero.second_maximum = INT_MIN;
        return zero;
    }
    if(start >= left && end <= right)
    {
        return tree[treeNode];
    }
    int mid = (start + end)/2;
    node q1 = query(arr,tree,start,mid,2*treeNode,left,right);
    node q2 = query(arr,tree,mid+1,end,2*treeNode + 1,left,right);
    node q3;
    q3.maximum = max(q1.maximum,q2.maximum);
    q3.second_maximum = min(max(q2.second_maximum,q1.maximum),max(q2.maximum,q1.second_maximum));

    return q3;
}

void printTree(node *tree,int n)
{
    cout<<endl;
    for(int i = 0; i < 3*n; i++)
    {
        cout<<tree[i].maximum<<" , "<<tree[i].second_maximum<<endl;
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    int *arr = new int[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    node *tree = new node[3*n];

    buildTree(arr,tree,1,n,1);
    // printTree(tree,n);

    int q;
    cin >> q;

    while(q--)
    {
        char a;
        int b,c;
        cin >> a >> b >> c;
        if(a == 'Q')
        {   
            node ans = query(arr,tree,1,n,1,b,c);
            cout<<ans.maximum + ans.second_maximum<<endl;
        }
        else if(a == 'U')
        {
            update(arr,tree,1,n,1,b,c);
        }
    }

    return 0;
}