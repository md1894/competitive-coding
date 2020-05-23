#include<list>
#include<iostream>
using namespace std;


/* list is not complex if you goto gfg you can get sufficient knowledge */
int main(){
    list<int> l;
    list<int>::iterator it;
    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    for(auto it:l){
        cout << it << "-->";
    }
    cout<<endl;
    it = l.begin();
    it++;
    /* insert 100 at 2nd position */
    l.insert(it,100);
    for(auto it:l){
        cout << it << "-->";
    }
    cout<<endl;
    /* if first or last element use pop_front / pop_back */
    l.remove(5);
    for(auto it:l){
        cout << it << "-->";
    }
    cout<<endl;
    l.sort();
     for(auto it:l){
        cout << it << "-->";
    }
    cout<<endl;
    return 0;
}