#include<bits/stdc++.h>
using namespace std;

int getBit(int num, int i){
    int mask = 1 << i;
    return ((num & mask) > 0) ? 1 : 0;
}

/* if the bit is 0 it will make it 1 */
int setBit(int num, int i){
    int mask = 1 << i;
    return mask | num;
}


/* if the bit is 1 it will make it 0 */
void clearBit(int& num, int i){
    int mask = ~(1<<i);
    num = num & mask;
}

/* update the i th bit with value in v */
void updateBit(int& num, int i, int v){
    int mask = ~(1<<i);
    /* first cleared that bit */
    int cleared_num = mask & num;
    /* prepared a mask like setBit but not with 1 with v */
    num = cleared_num | (v<<i);
}

int main(){
    int num;
    cin >> num;
    int i;
    cin >> i;
    cout << i << "th bit for the number " << num << " is " << getBit(num,i) << endl;
    int change;
    cin >> i;
    cout << "after setting " << i << "th bit  " << " the value is " << setBit(num,i) << endl;
    cin >> i;
    clearBit(num,i);
    cout << "after clearing " << i << "th bit " << "value is " << num << endl;
    int v;
    cin >> i >> v;
    updateBit(num,i,v);
    cout << "Updated value is " << num << endl;
    return 0;
}