#include <iostream>

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Factorial of negative numbers is not defined." << std::endl;
    } else {
        std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    }

    return 0;
}
