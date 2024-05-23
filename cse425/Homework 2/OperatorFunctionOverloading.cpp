//Q4. Write a Program to Implement the Concept of Operator and Function Overloading
#include<iostream>
using namespace std;

// Class for Function Overloading!
class Calculation{
    public:    // Access Specifier
    void add(int a, int b){ // Function to add two integers
        cout << "Sum of " << a << " & " << b << " is: " << a + b << endl;   // Print the sum of the integers
    }

    void add(double a, double b, double c){   // Function to add three double numbers
        cout << "Sum of " << a << ", " << b << " & " << c << " is: " << a + b + c << endl;  // Print the sum of the double numbers
    }
};

// Class for overloading the '+' operator for the Complex number!
class Complex{
    private:    // Access Specifier
    float real; // Variable to store the real part of the complex number
    float img;  // Variable to store the imaginary part of the complex number

    public: // Access Specifier
    Complex(float real, float img){ // Constructor to initialize the real and imaginary part of the complex number
        this->real = real;  // Initialize the real part of the complex number
        this->img = img;    // Initialize the imaginary part of the complex number
    }

    Complex operator+(Complex c2){  // Operator Overloading for the '+' operator
        Complex c3(0,0);    // Variable to store the sum of the complex numbers
        c3.real = this->real + c2.real; // Add the real part of the complex numbers
        c3.img = this->img + c2.img;    // Add the imaginary part of the complex numbers
        return c3;  // Return the sum of the complex numbers
    }

    void printComplex(){    // Function to print the complex number
        cout << "Complex Number: " << real << " + i" << img << endl;  // Print the complex number
    }
};

int main(){ // Main function
    // Output for function overloading
    cout << "Output for function overloading!" << endl; // Print the message

    Calculation cal;    // Object of the Calculation class
    cal.add(1, 3);  // Call the function to add two integers
    cal.add(3, 3.5, 6.7);   // Call the function to add three double numbers

    cout << endl;   // Print a new line

    // Output for Operator Overloading!
    cout << "Output for Operator Overloading!" << endl; // Print the message

    Complex c1(4, 5);   // Object of the Complex class
    Complex c2(5, 9);   // Object of the Complex class  
    Complex c3 = c1 + c2;   // Add the complex numbers
    c3.printComplex();  // Print the sum of the complex numbers

    return 0;
}
