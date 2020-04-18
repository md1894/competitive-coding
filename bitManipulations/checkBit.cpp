#include<iostream>
using namespace std;

bool checkBit(int i, int n){
    int mask = 1 << i;
    if((mask & n) == 0){
        return false;
    }else{
        return true;
    }
}

int main(){
    int n, i;
    cin >> n >> i;
    if(checkBit(n,i) == true){
        cout << "ON" << endl;
    }else{
        cout << "OFF" << endl;
    }
    return 0;
}