#include<queue>
#include<iostream>
using namespace std;


/*
priority_queue<int> pq; --> max heap
priority_queue<int,vector<int>,greater<int>> pq; --> min_heap;
greater<int> --> comparator class which is a template class
vector<int> --> it is the container class that will internally hold the pq elements
*/


/*
problem statement:-->
 we have to implement a priority queue such that , candidate with more marks will have
 more priority, and if marks are same then candidate with high age will be given more 
 priority
*/

class Candidate{
    public:
        int age;
        int marks;
        string name;


        Candidate(int age, int marks, string name){
            this->age = age;
            this->marks = marks;
            this->name = name;
        }
};

class CandidateComparison{
    public:

    /*
    takeaway--> if true is returned then position will alter
    */
    bool operator()(const Candidate& parentNode, const Candidate& childNode){
        if(parentNode.marks < childNode.marks){
            /* here returning true means that child node is having high mark */
            /* so we have to give child node the higher priority than the parent */
            /* now child and parent will swap the position */
            return true;
        }else if(parentNode.marks > childNode.marks){
            /* means that parent is at the right position */
            /* now repositioning will happen */
            return false;
        }else{
            if(parentNode.age >= childNode.age){
                /* if marks are same then if parent age is already greater than or equal to child */
                /* no repositioning will happen */
                return false;
            }else{
                /* if child have higher age then , swapping will happen */
                /* because person having more age will be given higher priority */
                return true;
            }
        }
    }  
};

int main(){
    priority_queue<Candidate, vector<Candidate>, CandidateComparison > pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name;
        int marks, age;
        cin >> name >> marks >> age;
        Candidate c(age,marks,name);
        pq.push(c);
    }
    while(pq.empty() == false){
        Candidate c = pq.top();
        cout << c.name << " marks--> " << c.marks << " age--> " << c.age << endl;
        pq.pop();
    }
    return 0;
}

/*
11
mehul 558 26
dipak 525 25
kature 525 30
gavde 525 29
nakul 558 23
ruchita 525 24
kolap 510 27
akaya 510 24
rohya 400 25
pavan 510 28
mayur 523 30

output:-->
mehul marks--> 558 age--> 26
nakul marks--> 558 age--> 23
kature marks--> 525 age--> 30
gavde marks--> 525 age--> 29
dipak marks--> 525 age--> 25
ruchita marks--> 525 age--> 24
mayur marks--> 523 age--> 30
pavan marks--> 510 age--> 28
kolap marks--> 510 age--> 27
akaya marks--> 510 age--> 24
rohya marks--> 400 age--> 25
*/

/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
struct Compare
{
    bool operator()(pi const & a, pi const & b)
    {
         if(a.second < b.second)
         {
            return true;
         }
         else if(a.second > b.second)
         {
             return false;
         }
         else
         {
             if(a.first > b.first)
             {
                 return true;
             }
             return false;
         }
    }
};

int main()
{
    priority_queue<pi , vector<pi>, Compare> pq;
    pq.push({1, 5});
    pq.push({5, 15});
    pq.push({7, 15});
    pq.push({10, 2});
    pq.push({1, 10});
    while(pq.empty() == false){
        cout << pq.top().first << " -- " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
*/

/*
5 -- 15                                                                                                                   
7 -- 15                                                                                                                   
1 -- 10                                                                                                                   
1 -- 5                                                                                                                    
10 -- 2
*/
