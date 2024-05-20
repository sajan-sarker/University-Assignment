// Q2. Write a Program to Check Palindrome.
#include<iostream>
using namespace std;

string checkPalindrome(string statement){
    int first = 0;
    int last = size(statement) - 1;

    while (first < last){
        if (statement[first] != statement[last]){
            return " not ";
        }
        first ++;
        last --;
    }
    return " ";
}

int main(){
    string statement1, statement2; 

    cout << "Enter 1st Statement: ";
    getline(cin, statement1);
    cout << "Enter 2nd Statement: ";
    getline(cin, statement2);
    cout << endl;

    cout << "'" << statement1 << "'" << "is" << checkPalindrome(statement1) << "Palindrome!" << endl;
    cout << endl;
    cout << "'" << statement2 << "'" << "is" << checkPalindrome(statement2) << "Palindrome!" << endl;

    return 0;
}