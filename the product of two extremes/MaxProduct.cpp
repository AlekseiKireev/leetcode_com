#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Функция для нахождения двух минимальных значений в массиве
pair<int, int> findTwoMinValues(const vector<int>& arr) {
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int num : arr) {
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    return {min1, min2};
}

// Функция для нахождения двух максимальных значений в массиве
pair<int, int> findTwoMaxValues(const vector<int>& arr) {
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int num : arr) {
        if (num >= max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }
    return {max1, max2};
}

// Функция для нахождения пары с максимальным произведением
pair<int, int> findMaxProductPair(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must have at least two elements.");
    }

    pair<int, int> minPair = findTwoMinValues(arr);
    pair<int, int> maxPair = findTwoMaxValues(arr);

    int product1 = minPair.first * minPair.second;
    int product2 = maxPair.first * maxPair.second;

    return (product1 > product2) ? minPair : maxPair;
}

int main() {
    vector<int> arr = {1, -4, 3, -6, 7, 0};
    try {
        pair<int, int> result = findMaxProductPair(arr);
        cout << "Pair with maximum product: (" << result.first << ", " << result.second << ")" << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
