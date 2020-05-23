#include <set>
#include <iostream>
using namespace std;

/* set --> contains distinct set of values */
/* multiset --> contains set of values (have repitition) */
/* multimap --> more than one value can be mapped to a same key */
typedef multiset<int>::iterator IT;

/* output-->
10 47 47 55 70 70 70 70 70 97 97 97 105 105 
10 55 70 70 70 70 70 97 97 97 105 105 
Found the element now 55 is no more 
NOT FOUND !!! 
10 70 70 70 70 70 97 97 97 105 105 
70 70 70 70 70 
*/

int main(){
    multiset<int> multiSet;
    multiSet.insert(10);
    multiSet.insert(70);
    multiSet.insert(55);
    multiSet.insert(47);
    multiSet.insert(47);
    multiSet.insert(105);
    multiSet.insert(97);
    multiSet.insert(97);
    multiSet.insert(97);
    multiSet.insert(105);
    multiSet.insert(70);
    multiSet.insert(70);
    multiSet.insert(70);
    multiSet.insert(70);
    for(auto it : multiSet){
        cout << it << " ";
    }
    cout << endl;
    /* all the occurances are deleted from multiset */
    multiSet.erase(47);
    for(auto it : multiSet){
        cout << it << " ";
    }
    cout << endl;
    multiset<int>::iterator it = multiSet.find(55);
    if(it != multiSet.end()){
        cout << "Found the element now 55 is no more " << endl;
        multiSet.erase(55);
    }
    it = multiSet.find(1001);
    if(it == multiSet.end()){
        cout << "NOT FOUND !!! " << endl;
    }
     for(auto it : multiSet){
        cout << it << " ";
    }
    cout << endl;
    /* display all element have value equal to 70 */
    pair<IT,IT> itPair = multiSet.equal_range(70);
    for(auto it = itPair.first; it != itPair.second; it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;   
}