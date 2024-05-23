// Q3. Write a C++ Program to Print the Given String in Reverse Order Using Recursion.
#include<iostream>
using namespace std;

void reverseString(string statement, int index){    // Function to reverse the statement
    if(index == -1){    // Check if the index is -1
        return; // Return if the index is -1
    }
    cout << statement[index];   // Print the character at the index
    reverseString(statement, index - 1);    // Call the function recursively with the decremented index
}

int main(){ // Main function
    string statement;   // Variable to store the statement
    cout << "Enter a statement for reverse: ";  // Ask the user to enter a statement
    getline(cin, statement);    // Get the statement from the user

    int len = size(statement) - 1;  // Variable to store the length of the statement

    cout << "Reverse of the statement is: ";    // Print the message
    reverseString(statement, len);  // Call the function to reverse the statement
    return 0;
}