//Q4. Write a Program to Implement the Concept of Operator and Function Overloading
#include<iostream>
using namespace std;

// Class for Function Overloading!
class Calculation{
    public:
    void add(int a, int b){
        cout << "Sum of " << a << " & " << b << " is: " << a + b << endl;
    }

    void add(double a, double b, double c){
        cout << "Sum of " << a << ", " << b << " & " << c << " is: " << a + b + c << endl;
    }
};

// Class for overloading the '+' operator for the Complex number!
class Complex{
    private:
    float real;
    float img;

    public:
    Complex(float real, float img){
        this->real = real;
        this->img = img;
    }

    Complex operator+(Complex c2){
        Complex c3(0,0);
        c3.real = this->real + c2.real;
        c3.img = this->img + c2.img;
        return c3;
    }

    void printComplex(){
        cout << real << " + i" << img << endl;
    }
};

int main(){
    // Output for function overloading
    cout << "Output for function overloading!" << endl;

    Calculation cal;
    cal.add(1, 3);
    cal.add(3, 3.5, 6.7);

    cout << endl;

    // Output for Operator Overloading!
    cout << "Output for Operator Overloading!" << endl;

    Complex c1(4, 5);
    Complex c2(5, 9);
    Complex c3 = c1 + c2;
    c3.printComplex();

    return 0;
}
