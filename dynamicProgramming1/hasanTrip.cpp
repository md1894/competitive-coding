/*
Hasan and Trip
Send Feedback
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/

#include <bits/stdc++.h>
#define DOUBLE_MIN -1e9
using namespace std;

class city{
  public:
    double x;
    double y;
    double f;
};

double calcDistance(city a, city b){
    double d1 = (a.x-b.x)*(a.x-b.x);
    double d2 = (a.y-b.y)*(a.y-b.y);
    return sqrt(d1+d2);
}

/*
1. i will stand on the current city and i will calculate net point 
   i will get when i travel from current (i) to each (j)
2. i will keep on doing this for every city, which will come one after current
   j --> i+1 to n
   its a unique and different problem, just try to understand the intution.
*/
double hasanTrip(city* c, int n){
    double* dp = new double[n];
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = DOUBLE_MIN;
    }
    for(int i = 0; i < n; i++){
        dp[i] += c[i].f;
        for(int j = i + 1; j < n; j++){
            double dist = calcDistance(c[i], c[j]);
            dp[j] = max(dp[j], dp[i] - dist);
        }
    }
    double ans = dp[n-1];
    delete [] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    city* c = new city[n];
    for(int i = 0; i < n; i++){
        cin >> c[i].x >> c[i].y >> c[i].f;
    }
    cout<<fixed;
    cout.precision(6);
    cout<<hasanTrip(c,n)<<endl;
    return 0;
}