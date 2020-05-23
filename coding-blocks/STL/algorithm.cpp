#include<algorithm>
#include<iostream>
using namespace std;

/* InputIterator find (InputIterator first, InputIterator last, const T& val) */
/*
first,last :
Input iterators to the initial and final positions in a sequence. The range
searched is [first,last), which contains all the elements between first and
last, including the element pointed by first but not the element pointed by last.

val :
Value to be search in the range

Return Value :
An iterator to the first element in the range that compares equal to val.
If no elements match, the function returns last. 
*/

int main(){
    /* find function demo */
    /* in the same manner i can apply to vector */
    int a[] = {3,6,7,1,9,90,45};
    int n = sizeof(a)/sizeof(int);
    /* this function returns the address of the block where key is present */
    /* key is basically the element that you are looking for */
    int* i = find(a,a+n,90);
    cout << "found " << *i << " at "<< i-a << endl;
    /* case where you search for the element which is not present */
    i = find(a,a+n,37);
    /* when you do so, it will return the size of the array */
    cout << *i << " : " << i-a <<endl;
    /* to calculate the index --> returned address - base address */
    /* if index == size, --> element not found */
    return 0;
}