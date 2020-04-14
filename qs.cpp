#include<iostream>
//#include "Solution.h"
using namespace std;


void swp(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int input[], int start, int end){
    // find no of elements smaller than pivot
    int count = start;
    int pivot = input[start];
    for(int i = start+1; i <= end; i++){
        if(input[i] < pivot)
            count++;
    }
    swp(&input[count], &input[start]);
    int i = start, j = end;
    while(i < j){
        if(input[i] < pivot)
            i++;
        else if(input[j] >= pivot)
            j--;
        else{
            swp(&input[i], &input[j]);
            i++;
            j--;
        }
    }
    return count;
}

void qs(int input[], int start, int end){
    if(start < end){
        int q = partition(input, start, end);
        qs(input, start, q-1);
        qs(input, q+1, end);
    }
}


void quickSort(int input[], int size) {
    return qs(input, 0, size-1);
}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



