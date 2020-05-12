/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting 
the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    int start_time,finish_time,profit;
};

bool compare(Job j1, Job j2){
    return j1.finish_time < j2.finish_time;
}

int binarySearch(Job* input, int left, int right,int target){
    if(left <= right){
        int mid = (left+right)/2;
        if(input[mid].finish_time <= input[target].start_time){
            if(input[mid+1].finish_time <= input[target].start_time){
                return binarySearch(input,mid+1,right,target);
            }
            return mid;
        }else{
            return binarySearch(input,left,mid-1,target);
        }
    }else{
        return -1;
    }
}

int solve(Job* input, int n){
    sort(input,input+n,compare);
    int* dp = new int[n];
    dp[0] = input[0].profit;
    for(int i = 1; i < n; i++){
        int inclCurrentJob = input[i].profit;
        int latestNonConflictJob = binarySearch(input,0,i-1,i);
        if(latestNonConflictJob != -1){
            inclCurrentJob += dp[latestNonConflictJob];
        }
        dp[i] = max(inclCurrentJob,dp[i-1]);
    }
    int ans = dp[n-1];
    delete [] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Job* input = new Job[n];
    for(int i = 0; i < n; i++){
        cin >> input[i].start_time >> input[i].finish_time >> input[i].profit;
    }
    cout << solve(input,n) << endl;
    return 0;
}