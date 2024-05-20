// Q1. Write a Program to Find the Length of the String Without using strlen() Function.
#include<iostream>
using namespace std;

void getLen(string statement){
    int size = 0;
    for(int i = 0; statement[i] != '\0'; i++){
        size ++;
    }
    cout << "Given Statement is: " << statement << endl;
    cout << "Length of the statement is: " << size;
}

int main(){
    string statement;
    cout << "Enter a statement: ";
    getline(cin, statement);
    cout << endl;

    getLen(statement);

    return 0;
}

