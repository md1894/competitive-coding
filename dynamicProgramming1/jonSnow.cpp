/*
Jon Snow and his favourite number
Send Feedback
Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.
Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?
Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).
Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.
Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> ip, int n, int k, int x){
    vector<int> original(1025, 0);
    vector<int> result(1025,0);
    original = ip;
    result = ip;
    while(k--){
        int processedEl = 0;
        for(int i = 0; i <= 1024; i++){
            if(original[i] != 0){
                processedEl += original[i];
                if(processedEl % 2 == 0){
                    int p = original[i]/2;
                    result[i^x] += p;
                    result[i] -= p;
                }else{
                    int p = (original[i]+1)/2;
                    result[i^x] += p;
                    result[i] -= p;
                }
            }
        }
        original = result;
    }
    for(int i = 1024; i >= 0; i--){
        if(result[i] != 0){
            cout << i << " ";
            break;
        }
    }
    for(int i = 0; i <= 1024; i++){
        if(result[i] != 0){
            cout << i << " ";
            cout << endl;
            break;
        }
    }
}

int main(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> ip(1025, 0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        ip[num]++;
    }
    solve(ip, n, k, x);
    return 0;
}