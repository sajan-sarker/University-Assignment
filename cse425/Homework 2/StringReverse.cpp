// Q3. Write a C++ Program to Print the Given String in Reverse Order Using Recursion.
#include<iostream>
using namespace std;

void reverseString(string statement, int index){
    if(index == -1){
        return;
    }
    cout << statement[index];
    reverseString(statement, index - 1);
}

int main(){
    string statement;
    cout << "Enter a statement for reverse: ";
    getline(cin, statement);

    int len = size(statement) - 1;

    reverseString(statement, len);
    return 0;
}