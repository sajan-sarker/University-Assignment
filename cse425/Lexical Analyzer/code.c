// Input of the lexical_analyzer.py file
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

void main() {
    int num1 = 3, num2 = 5, result;
    
    result = sum(num1, num2);
    
    printf("The sum is: %d\n", result);
}