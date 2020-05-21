/*
Help Me Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
class trie{
 
 public:
     bool isterminal;
     trie* children[26];
 
    trie(){
        isterminal=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};
 
void insert1(string s,trie* head){
 
    trie* curr=head;
    for(int i=0;i<s.size();i++){
    
        if(curr->children[s[i]-'a']){
                curr=curr->children[s[i]-'a'];
        }
        else{
                trie *child=new trie();
                curr->children[s[i]-'a']=child;
                curr=child;
        }
    
        if(i==s.size()-1)
            curr->isterminal=true;
    
    }
}


void helper1(string s,trie* curr){

    if(curr->isterminal)
        cout<<s<<endl;

    for(int i=0;i<26;i++){
        char a='a'+i;
        if(curr->children[i]){
            helper1(s+a,curr->children[i]);
        }
    }
}


void query(string s,trie* head){
    trie* curr=head;
    int flag=0;
    for(int i=0;i<s.size();i++){
        if(curr->children[s[i]-'a']){
            curr=curr->children[s[i]-'a'];
        }
        else{
            flag=1;
            break;
        }
    }

    if(flag==1){
        cout<<"No suggestions"<<endl;
        insert1(s,head);
        return;
    }
    else{
        if(curr->isterminal)
            cout<<s<<endl;

        for(int i=0;i<26;i++){
            char a='a'+i;
            if(curr->children[i]){
                helper1(s+a,curr->children[i]);
            }
        }

    }

}
 
signed main(){
    
    int n;
    cin>>n;
    trie* head=new trie();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert1(s,head);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        query(s,head);
    }
    return 0;
}