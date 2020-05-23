#include<cstring>
#include<iostream>
using namespace std;

/* if we donot give any string, NULL then previous strings next token will be returned */
/* process to tokenize the string */
int main(){
    char s[] = "my name is mehul dubey";
    char* token = strtok(s," ");
    /* it internally maintains a static array */
    while(token != NULL){
        cout << token << endl;
        /* this function will give the next token automatically */
        token = strtok(NULL," ");
    }
    return 0;
}