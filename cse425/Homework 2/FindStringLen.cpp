// Q1. Write a Program to Find the Length of the String Without using strlen() Function.
#include<iostream>
using namespace std;

void getLen(string statement){ // Function to get the length of the string
    int size = 0;   // Variable to store the length of the string
    for(int i = 0; statement[i] != '\0'; i++){  // Loop to iterate through the string
        size ++;    // Increment the size variable
    }
    cout << "Given Statement is: " << statement << endl;    // Print the statement
    cout << "Length of the statement is: " << size; // Print the length of the statement
}

int main(){ // Main function
    string statement;   // Variable to store the statement
    cout << "Enter a statement: ";  // Ask the user to enter a statement
    getline(cin, statement);    // Get the statement from the user
    cout << endl;   // Print a new line

    getLen(statement);  // Call the function to get the length of the statement

    return 0;   
}
