#include<bits/stdc++.h>
using namespace std;

class st{
  public:
    string name;
    int marks;
};

bool cm(st e1, st e2){
    return e1.marks > e2.marks;
}

int main()
{
    int n;
    cin >> n;
    st* s = new st[n];
    for(int i = 0; i < n; i++){
        cin >> s[i].name;
        int a, b, c;
        cin >> a >> b >> c;
        s[i].marks = a+b+c;
    }
    sort(s, s+n, cm);
    for(int i = 0; i < n; i++){
        cout << s[i].name << " " << i + 1 <<endl; 
    }
	return 0;
}
