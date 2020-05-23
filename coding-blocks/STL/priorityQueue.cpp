#include<queue>
#include<iostream>
using namespace std;


/*
priority_queue<int> pq; --> max heap
priority_queue<int,vector<int>,greater<int>> pq; --> min_heap;
greater<int> --> comparator class which is a template class
vector<int> --> it is the container class that will internally hold the pq elements
*/

class Person{
    public:
    int age;
    string name;

    Person(int age, string name){
        this->name = name;
        this->age = age;
    }
};

class PersonCompare{
    public:
    /* compulsory we have to overload () operator */
    bool operator()(Person p1, Person p2){
        /* ordering depends on this step */
        return p1.age < p2.age;
    }
};

int main(){
    priority_queue<Person,vector<Person>,PersonCompare> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int age;
        string name;
        cin >> age >> name;
        Person p(age,name);
        pq.push(p);
    }
    cout << "----------------------" << endl;
    /* extracting all the elements of priority queue */
    while(!pq.empty()){
        Person p = pq.top();
        cout << p.name << " " << p.age << endl;
        pq.pop();
    }
    return 0;
}