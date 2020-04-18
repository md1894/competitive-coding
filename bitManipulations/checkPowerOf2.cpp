#include<iostream>
using namespace std;

bool check(int n){
    return !(n & (n-1));
}

int main(){
    int n;
    cin >> n;
    if(check(n) == true){
        cout << "yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}