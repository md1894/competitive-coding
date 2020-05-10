/*
Smallest Super-Sequence
Send Feedback
Given two strings S and T, 
find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as 
the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, 
then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be 
"abc" which has length=3.
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int smallestSuperSequence(char str1[], int len1, char str2[], int len2) {
    
}

int main()
{
    char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len;
    return 0;
}