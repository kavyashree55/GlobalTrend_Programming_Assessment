#include <string>
#include <cctype>
#include <iostream>

bool isAlphabetic(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}
int main() {
    std::string str1 = "hello";
    std::string str2 = "hello123";

    std::cout << std::boolalpha;
    std::cout << "Is '" << str1 << "' alphabetic? " << isAlphabetic(str1) << std::endl;
    std::cout << "Is '" << str2 << "' alphabetic? " << isAlphabetic(str2) << std::endl;

    return 0;
}
