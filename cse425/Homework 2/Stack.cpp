// Q5. Write a Program for the Implementation of Stacks Using an Array using object oriented modeling. 
#include<iostream>
using namespace std;

#define n 1000

class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout << "Stack is Full!";
            return;
        }
        
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<< "No Element to POP" << endl;
            return;
        }
        top --;
    }

    int Top(){
        if(top == -1){
            cout << "No element on stack" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }
};

int main(){
    Stack s;
    
    cout << "Check Stack: " << s.isEmpty() << endl;
    s.push(211);
    s.push(11);
    s.push(31);
    cout << "Check Top: " << s.Top() << endl;
    s.pop();
    s.pop();
    cout << "Check Top: " << s.Top() << endl;
    cout << "Check Stack: " << s.isEmpty() << endl;
}