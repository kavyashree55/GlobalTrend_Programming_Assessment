#include <iostream>
#include <vector>
#include <algorithm>

int maxDifference(std::vector<int>& arr) {
    if (arr.size() < 2) {
        throw std::invalid_argument("Array must have at least two elements");
    }

    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());

    if (minVal == maxVal) {
        throw std::invalid_argument("All elements in the array are equal");
    }

    int diff1 = maxVal - minVal;
    std::sort(arr.begin(), arr.end());
    int diff2 = *std::max_element(arr.begin(), arr.end() - 1) - *std::min_element(arr.begin(), arr.end() - 1);

    return std::max(diff1, diff2);
}

int main() {
    std::vector<int> arr = {1, 10, 2, 4, 7, 3};

    try {
        int maxDiff = maxDifference(arr);
        std::cout << "Maximum difference between any two elements in the array is " << maxDiff << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
