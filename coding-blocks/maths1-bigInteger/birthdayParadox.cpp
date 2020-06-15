/*
what is the minimum number of people that should be present in a hall so that
there's 50% chance of two people having the same birthday
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  float num = 365, den = 365;
  float p;
  int people = 0;
  float x = 1.0;
  cin >> p;
  if(p == 1.0){
    cout << "366" << endl;
    return 0;
  }
  while(x > 1-p){
    x = x*(num/den);
    num--;
    people++;
    cout << "Min people " << people << " probability " << (1-x)*100 << "%" << endl;
  }
  return 0;
}
