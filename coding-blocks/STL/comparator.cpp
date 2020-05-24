#include<bits/stdc++.h>
using namespace std;

/* see this function favours when first is greater tha second */
/* it means that this will sort the list by descending order */
bool compareDescending(int firstElement, int secondElement){
    /* returns true when first is larger than second */
    return firstElement > secondElement;
}


/*
this function favours when first is smaller than second
it means that this function is gonna sort the list by ascending order
*/
bool compareAscending(int firstElement, int secondElement){
    /* returns true when first is smaller than second */
    return firstElement < secondElement;
}

int main(){
    int a[] = {2,5,1,6,11,9};
    int n = sizeof(a)/sizeof(int);
    sort(a,a+n,compareAscending);
    for(auto i : a){
        cout << i << " ";
    }
    cout << endl;
    cout << "-------------------" << endl;
    sort(a,a+n,compareDescending);
    for(auto i : a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}