#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int solve(vector<int>& input){
    unordered_set<int> set_;
    int j = 0;
    int sum = 0;
    for(int i = 0; i < input.size(); i++){

        while(j < input.size() && set_.find(input[j]) == set_.end()){
            set_.insert(input[j]);
            j++;
        }
        int n = j - i;
        sum = (sum%MOD + ((n*(long)(n+1))/2)%MOD)%MOD;
        set_.erase(input[i]);
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> input;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        input.push_back(num);
    }
    cout << solve(input) << endl;
    return 0;
}