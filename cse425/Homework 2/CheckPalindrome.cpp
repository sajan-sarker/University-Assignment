// Q2. Write a Program to Check Palindrome.
#include<iostream>
using namespace std;

string checkPalindrome(string statement){   // Function to check if the statement is palindrome or not
    int first = 0;  // Variable to store the first index of the statement
    int last = size(statement) - 1; // Variable to store the last index of the statement

    while (first < last){   // Loop to iterate through the statement
        if (statement[first] != statement[last]){   // Check if the first and last index of the statement are not equal
            return " not "; // Return not if the statement is not palindrome
        }
        first ++;   // Increment the first index
        last --;    // Decrement the last index
    }
    return " "; // Return empty string if the statement is palindrome
}

int main(){ // Main function
    string statement1, statement2;  // Variables to store the statements

    cout << "Enter 1st Statement: ";    // Ask the user to enter the 1st statement
    getline(cin, statement1);   // Get the 1st statement from the user
    cout << "Enter 2nd Statement: ";    // Ask the user to enter the 2nd statement
    getline(cin, statement2);   // Get the 2nd statement from the user
    cout << endl;   // Print a new line

    cout << "'" << statement1 << "'" << "is" << checkPalindrome(statement1) << "Palindrome!" << endl;   // Print the result of the 1st statement
    cout << endl;   // Print a new line
    cout << "'" << statement2 << "'" << "is" << checkPalindrome(statement2) << "Palindrome!" << endl;   // Print the result of the 2nd statement

    return 0;   
}