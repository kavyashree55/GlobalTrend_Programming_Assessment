#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2;
    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        std::cout << "Error: GCD is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << std::endl;
    }

    return 0;
}
