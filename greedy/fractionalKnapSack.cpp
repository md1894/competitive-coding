/*
Fractional Knapsack
Send Feedback
You want to paint your house. 
The total area of your house is D units. 
There are a total of N workers. 
The ith worker is available after time Ti, has hiring cost Xi and speed Yi. 
This means he becomes available for hiring from time Ti and remains available after that. 
Once available, you can hire him with cost Xi, after which he will start painting the house immediately, 
covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and 
can also hire or fire him at any later point of time. 
However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, 
such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", 
the number of workers and the area of your house respectively. 
The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", 
described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

class Painter{
    public:
    	int available_from_time;
    	int cost_of_hiring;
    	int speed;
};

bool compare(Painter p1, Painter p2){
    
    if(p1.available_from_time == p2.available_from_time){
        /* speed will be the tie breaker */
        if(p1.speed == p2.speed){
            /* last way to decide on the basis of cost */
            return p1.cost_of_hiring < p2.cost_of_hiring;
        }
        return p1.speed > p2.speed;
    }
    /* first priority to who ever is available from the earliest */
    return p1.available_from_time < p2.available_from_time;
}

int solve(Painter* input, int n, long totalArea){
    sort(input,input+n,compare);
    long areaCovered = 0;
    int currentWorker = 0;
    int cost = input[0].cost_of_hiring;
    for(int i = 1; i < n && areaCovered < totalArea; i++){
        long time_gap = input[i].available_from_time - input[i-1].available_from_time;
        areaCovered += time_gap*(input[currentWorker].speed);
        if(areaCovered >= totalArea){
            return cost;
        }
        /* i am comparing my currently working painter with the ith painter */
        /* if ith painter is better than i will hire him */
        if(input[currentWorker].speed < input[i].speed){
            currentWorker = i;
            cost += input[i].cost_of_hiring;
        }
    }
    return cost;
}

int main()
{
    int N;
    long D;
    cin >> N >> D;
    Painter* input = new Painter[N];
    for(int i = 0; i < N; i++){
        cin >> input[i].available_from_time >> input[i].cost_of_hiring >> input[i].speed;
    }
    cout << solve(input, N, D) << endl;
    delete [] input;
    return 0;
}