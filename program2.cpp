#include <string>
#include <unordered_map>
#include <ostream>
#include <iostream>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++) {
        char c = s[end];
        if (charIndexMap.find(c)!= charIndexMap.end()) {
            start = std::max(start, charIndexMap[c] + 1);
        }
        charIndexMap[c] = end;
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}
int main() {
    std::string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring without repeating characters: " << length << std::endl;
    return 0;
}
