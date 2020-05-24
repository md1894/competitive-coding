/*
Nishant is a very naughty boy in Launchpad Batch. 
One day he was playing with strings, and randomly shuffled them all. 
Your task is to help Nishant Sort all the strings ( lexicographically ) but 
if a string is present completely as a prefix in another string, 
then string with longer length should come first. 
Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - 
then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman

Sample Output
apple
batman
bat

Explanation
In mathematics, the lexicographic or lexicographical order 
(also known as lexical order, dictionary order, alphabetical order or lexicographic(al) product) 
is a generalization of the way words are alphabetically ordered based on the alphabetical order of their 
component letters.
*/

#include<bits/stdc++.h>
using namespace std;

/*
s1 --> first string, s2 --> second string
if s1 >= s2 (in length) and s1 has s2 as a prefix:
    yes this is the desired sorting that we want, hence return true at this point;
else if s2 >= s1(in length) and s2 has s1 as a prefix:
    no this time s2 must come forward , hence return false at this point
else
    return s1 < s2; --> (s1 must be lexicographically smaller(dictionary order))
*/
bool compare(string s1, string s2){
    if(s1.size() >= s2.size() && s1.substr(0,s2.size()) == s2){
        return true;
    }else if(s2.size() >= s1.size() && s2.substr(0,s1.size()) == s1){
        return false;
    }else{
        return s1 < s2;
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> input;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        input.push_back(s);
    }
    sort(input.begin(), input.end(), compare);
    for(auto curr : input){
        cout << curr << endl;
    }
    return 0;
}