#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;
/* when we want to take a user defined data type as a key */
/* just configuration thing functionality will be the same */
class Student{
    public:
    string firstName;
    string lastName;
    int rollNo;

    Student(string fn, string ln,int rn){
        firstName = fn;
        lastName = ln;
        rollNo = rn;
    }

    bool operator==(const Student& s)const{
        return s.rollNo == this->rollNo;
    }    
};

class HashStudent{
    public:

    /* this is the hashfunction */
    /* implementation is simple */
    size_t operator()(const Student& s1)const{
        return s1.firstName.length() + s1.lastName.length(); 
    }
};

int main(){
    unordered_map<Student,int,HashStudent> student_map;
    Student s1("mehul","dubey",121);
    Student s2("Dipya","Aglave",2);
    Student s3("pankya","Devkar",140);
    Student s4("Akya","Bhau",122);
    student_map.insert(make_pair(s1,550));
    student_map[s2] = 450;
    student_map[s3] = 457;
    student_map[s4] = 458;
    unordered_map<Student,int,HashStudent>::iterator it = student_map.begin();
    while(it != student_map.end()){
        cout << it->first.firstName << " " << it->second << endl;
        it++;
    }
    /* output -->
    Akya 458
    pankya 457
    mehul 550
    Dipya 450
    */
    return 0;
}