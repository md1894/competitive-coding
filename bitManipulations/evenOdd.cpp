#include<iostream>
using namespace std;

bool check(int n){
    if((n & 1) == 0)
        return true;
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    if(check(n) == true){
        cout << "even" << endl;
    }else{
        cout << "odd" << endl;
    }
    return 0;
}