/*
Ravi has been given two strings named string1 and string 2. 
He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. 
Help him to find the substring

Input Format

The first line of the input contains string1. 
String1 can be a string containing spaces also. 

The second line of the input contains string2. 
String2 can be a string containing spaces also.

Constraints
Length of both the strings can be at max 10^4

Output Format
Output the substring in a single line. 
If no such substring exist then output "No String" without quotes

Sample Input
qwerty asdfgh qazxsw
qas

Sample Output
qazxs

Explanation
The substring "qazxs" is the shortest substring of s1 that contains all the characters of s2.
*/

#include<bits/stdc++.h>
using namespace std;

/* this is an interesting problem try to read comment and recall the algorithm */
/* time complexity is O(N) N--> length of longer string */
string stringWindow(string text,string pattern){
    /* n--> main string length, m--> pattern/small string length */
    int n = text.length();
    int m = pattern.length();
    /* starting index of the final substring that satisfies the condition */
    int startIndex = -1;
    /* start will be the starting point of the currently found substring */
    /* count will keep the track weather we found all the characters in main string */
    int start = 0, count = 0;
    /* record the frequency of all the characters in main string */
    int hash_text[257] = {0};
    /* record the frequency of all the character in the pattern string */
    int hash_pattern[257] = {0};
    /* overall min length */
    int minLength = INT_MAX;
    /* iterate over the pattern to record frequency of all the characters */
    for(int i = 0; i < m; i++){
        hash_pattern[pattern[i]]++;
    }
    for(int j = 0; j < n; j++){
            /* increment the frequency of current character in main string */
            hash_text[text[j]]++;
            /* condition satisfied */
            /* if character present in pattern and its frequency in main string is less than or equal to required */
            /* required --> frequency in pattern string */
            if(hash_pattern[text[j]] != 0 && hash_text[text[j]] <= hash_pattern[text[j]]){
                count++;
            }
            if(count == m){
                    /* loop will move the start forward based on the condition */
                    /* condition is --> that characters starting from start must be unnecessary extra characters */
                    /*
                    condition 1 : text[start] is present but is more than the required --> c1 (update frequency)
                    condition 2 : text[start] is at start and not present in pattern
                    */
                    while(hash_text[text[start]] > hash_pattern[text[start]] || hash_pattern[text[start]] == 0){
                        if(hash_text[text[start]] > hash_pattern[text[start]]){
                                /*
                                we are nullifying the effect characters, if any small substring might be present at
                                later part
                                */
                                hash_text[text[start]]--;
                        }
                        start++;
                    }
                    int currentLength = j - start + 1;
                    if(currentLength < minLength){
                        minLength = currentLength;
                        startIndex = start;
                    }
            }
    }
    if(startIndex == -1){
        return "No String";
    }
    return text.substr(startIndex,minLength);
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    cout << stringWindow(text,pattern) << endl;
    return 0;
}