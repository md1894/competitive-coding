/*
The idea is to maintain an interval [L, R] which is the interval with max R
such that [L,R] is prefix substring (substring which is also prefix). 

Steps for maintaining this interval are as follows – 

1) If i > R then there is no prefix substring that starts before i and 
   ends after i, so we reset L and R and compute new [L,R] by comparing 
   str[0..] to str[i..] and get Z[i] (= R-L+1).

2) If i <= R then let K = i-L,  now Z[i] >= min(Z[K], R-i+1)  because 
   str[i..] matches with str[K..] for atleast R-i+1 characters (they are in
   [L,R] interval which we know is a prefix substring).     
   Now two sub cases arise – 
      a) If Z[K] < R-i+1  then there is no prefix substring starting at 
         str[i] (otherwise Z[K] would be larger)  so  Z[i] = Z[K]  and 
         interval [L,R] remains same.
      b) If Z[K] >= R-i+1 then it is possible to extend the [L,R] interval
         thus we will set L as i and start matching from str[R]  onwards  and
         get new R then we will update interval [L,R] and calculate Z[i] (=R-L+1).
*/

#include<bits/stdc++.h>
using namespace std;

/*
the best way to revise this is to dry run an example on this
input -> mehuldubeyuldy
pattern -> uld
answer will come out as 3 and 10
*/

void buildZ_Array(string str, int Z[]){
    int n = str.length();
    int left = 0, right = 0;
    Z[0] = 0;
    for(int i = 1; i < n; i++){
        /* 
        if 'i' lies outside the window then answer for this is not saved earlier
        you have to make comparisons 
        */
        if(i > right){
            left = i;
            right = i;
            while(right < n && str[right-left] == str[right]){
                right++;
            }
            Z[i] = right - left;
            right--;
        }else{
            int k = i - left;
            /* this indicates that answer previously saved answer we can use */
            if(Z[k] <= right-i){
                Z[i] = Z[k];
            }else{
                /* 
                    if the index after adding previously saved answer crosses the window
                    then keep right as it is and bring left to i
                    just compare as done in previous step
                */
                left = i;
                while(right < n && str[right] == str[right-left]){
                    right++;
                }
                Z[i] = right-left;
                right--;
            }
        }
    }
}

void zAlgo(string str, string pattern){
    string inputString = pattern + "$" + str;
    int n = inputString.length();
    int Z[n];
    /* this line , line # 60 is the heart of this algorithm */
    buildZ_Array(inputString,Z);
    int m = pattern.length();
    for(int i = 0; i < n; i++){
        if(Z[i] == m){
            cout << i-m-1 << " ";
        }
    }
}

int main(){
    string str, pattern;
    cin >> str >> pattern;
    zAlgo(str,pattern);
    return 0;
}