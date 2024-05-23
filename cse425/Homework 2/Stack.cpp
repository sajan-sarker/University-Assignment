// Q5. Write a Program for the Implementation of Stacks Using an Array using object oriented modeling. 
#include<iostream>
using namespace std;

#define n 1000  // Define the size of the stack

class Stack{
    int* arr;   // Pointer to store the stack
    int top;    // Variable to store the top of the stack

    public:
    Stack(){    // Constructor to initialize the stack
        arr = new int[n];   // Initialize the stack
        top = -1;   // Initialize the top of the stack
    }

    void push(int x){   // Function to push an element to the stack
        if(top == n-1){ // Check if the stack is full
            cout << "Stack is Full!";   // Print the message
            return; 
        }
        // else: 
        top++;  // Increment the top of the stack
        arr[top] = x;   // Push the element to the stack
    }

    void pop(){ // Function to pop an element from the stack
        if(top == -1){  // Check if the stack is empty
            cout<< "No Element to POP" << endl; // Print the message
            return;
        }
        top --; // else: decrement the top of the stack
    }

    int Top(){  // Function to get the top element of the stack
        if(top == -1){  // Check if the stack is empty
            cout << "No element on stack" << endl;  // Print the message
            return -1;  // Return -1
        }
        return arr[top];    // Return the top element of the stack
    }

    bool isEmpty(){ // Function to check if the stack is empty
        return top == -1;   // Return true if the stack is empty
    }
};

int main(){
    Stack s;    // Object of the Stack class
    
    cout << "Check Stack: " << s.isEmpty() << endl; // Check if the stack is empty
    s.push(211);    // Push an element to the stack
    s.push(11); // Push an element to the stack
    s.push(31); // Push an element to the stack
    cout << "Check Top: " << s.Top() << endl;   // Check the top element of the stack
    s.pop();    // Pop an element from the stack
    s.pop();    // Pop an element from the stack
    cout << "Check Top: " << s.Top() << endl;   // Check the top element of the stack
    cout << "Check Stack: " << s.isEmpty() << endl; // Check if the stack is empty
    s.pop();    // Pop an element from the stack
    cout << "Check Top: " << s.Top() << endl;   // Check the top element of the stack
}