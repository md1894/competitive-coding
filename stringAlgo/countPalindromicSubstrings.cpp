/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

#include <iostream>
#include<string.h>
using namespace std;


/* study geek for geeks for the same problem and try to figure out the difference */
/* by applying the same logic we can find the length of the longest palindromic substring */
int countPalindromeSubstrings(char s[]) {
    int n = strlen(s);
    int count = 0;
    for(int i = 0; i < n; i++){
        count++;
        int left = i-1;
        int right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]){
            count++;
        }
        int mid1 = i;
        int mid2 = i+1;
        if(s[mid1] == s[mid2]){
            count++;
            left = mid1-1;
            right = mid2+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                count++;
            }
        }
    }
    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}