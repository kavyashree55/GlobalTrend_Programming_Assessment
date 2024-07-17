#include <iostream>

int sumOfDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int num;
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Error: Sum of digits is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "Sum of digits of " << num << " is " << sumOfDigits(num) << std::endl;
    }

    return 0;
}
