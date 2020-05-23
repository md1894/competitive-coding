#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

/* lower_bound-->:: returns value that is greater than or equal to key */
/* if no element is greater than key, it returns last */
/* upper_bound-->:: > key (strictly greater than key, first occurance) */
/* in a sorted sequence we can use binary_search function */
int main(){
    /* apply inbuilt binary search */
    int a[] = {10,15,20,22,39,109,220,456,1590};
    set<int> s;
    int n = sizeof(a)/ sizeof(int);
    for(auto it: a){
        s.insert(it);
    }
    bool isPresent = binary_search(a,a+n,220);
    if(isPresent){
        cout << "yes we found it "<<endl;
        int* lb = lower_bound(a,a+n,220);
        cout << "its first occurance found at " << (lb-a) << endl;
        int* ub = upper_bound(a,a+n,220);
        cout << "number greater than 220 starts at " << ub-a << endl;
    }

    isPresent = binary_search(s.begin(),s.end(),220);
    set<int>::iterator sIt;
    if(isPresent){
        cout << "yes we found it "<<endl;
        sIt = lower_bound(s.begin(),s.end(),220);
        cout << "lower bound for 220 in set is " << *sIt << endl;
        sIt = upper_bound(s.begin(), s.end(), 220);
        cout << "upper bound for 220 in set is " << *sIt << endl;
    }
    return 0;
}