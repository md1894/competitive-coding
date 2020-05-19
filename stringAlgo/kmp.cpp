#include<bits/stdc++.h>
using namespace std;

/* this function gives an array which is of same length as that of pattern */
/* each index of array gives the length of prefix that is a suffix at (i) */

/* 
lps[i] --> where to start matching in pattern after a mismatch at i+1
       --> length of longest suffix that is also a prefix starting from 0 to i (both inclusive) 
*/

/*
 example lps(dsgwadsgz) --> 000001230
*/
int* getLPS(string pattern){
    int len = pattern.length();
    int* lps = new int[len];
    int i = 1;
    int j = 0;
    lps[0] = 0;
    while(i < len){
        if(pattern[i] == pattern[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool kmpSearch(string input, string pattern){
    int n = input.length();
    int m = pattern.length();
    int* lps = getLPS(pattern);
    int i = 0, j = 0;
    while(i < n && j < m){
        if(pattern[j] == input[i]){
            i++;
            j++;
        }else{
            if(j != 0){
                /* if there is a mismatch in the character */
                /* we will trace back to index before which already matched part is present */
                /* we will go to one index after a prefix which is also a suffix */
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    if(j == m){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s, p;
    cin >> s >> p;
    if(kmpSearch(s,p)){
        cout << "PATTERN FOUND" << endl;
    }else{
        cout << "PATTERN NOT FOUND" << endl;
    }
    return 0;
}