/*
Dean of NIT Silchar is going to visit Hostels of NIT Silchar. 
As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. 
Hostels are situated in 2D plane. 
You are given the coordinates of hostels and 
you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

Input:
First line of input contains Q Total no. of queries and K
There are two types of queries:

first type : 1 x y
For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel.
second type : 2
For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.

The Dean will always stay at his place ( origin ).
It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2
Output:
For each query of type 2 output the Rocket distance of Kth nearest hostel from Origin.

Constraints
1 < = k < = Q < = 105
-106 < = x , y < = 106


sample input:
9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6 
1 5 5
2

sample output:
200
162
98
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL getRocketDistance(LL x, LL y){
    return (x*x) + (y*y);
}

/* the whole idea to solve is problem is maintain a max priority queue of size k */
/* every time the top of this priority queue will be the kth nearest distance */
/* when query of type one comes, it will modify the priority_queue according to logic */

int main(){
    /* max priority queue */
    priority_queue<LL> pq;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int type;
        cin >> type;
        if(type == 1){
            LL x,y;
            /* co-ordinates for type one query */
            cin >> x >> y;
            LL rocketDistance = getRocketDistance(x,y);
            if(pq.size() < k){
                pq.push(rocketDistance);
            }else{
                if(rocketDistance < pq.top()){
                    pq.pop();
                    pq.push(rocketDistance);
                }
            }
        }else{
            cout << pq.top() << endl;
        }
    }
    return 0;
}