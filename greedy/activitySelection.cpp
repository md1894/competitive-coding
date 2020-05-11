/*
Activity Selection
Send Feedback
You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/

#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long int

struct Activity
{
    LL start;
    LL end;
};

bool operator <(Activity a,Activity b)
{
    if(a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main()
{
    //Write your code here
    int n;
    cin >> n;

    Activity *act = new Activity[n];
    for(int i = 0; i < n; i++)
        cin >> act[i].start >> act[i].end;

    sort(act,act+n);

    int cnt = 1;
    Activity prev = act[0];

    for(int i = 1; i < n; i++)
    {
        if(prev.end <= act[i].start)
        {
            cnt++;
            prev = act[i];
        }
    }

    cout << cnt << endl;
    
    return 0;
}