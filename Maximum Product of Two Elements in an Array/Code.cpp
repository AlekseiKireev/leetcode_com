#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int maxProduct(const vector<int>& nums) {
    int max1 = numeric_limits<int>::min(); // Наибольшее число в массиве
    int max2 = numeric_limits<int>::min(); // Второе наибольшее число в массиве
    int min1 = numeric_limits<int>::max(); // Наименьшее число в массиве
    int min2 = numeric_limits<int>::max(); // Второе наименьшее число в массиве

    for (int num : nums) {
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }

        if (num >= max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }

    // Максимальное произведение будет либо произведением двух наибольших чисел,
    // либо произведением двух наименьших чисел (если они отрицательные).
    return max(max1 * max2, min1 * min2);
}

int main() {
    vector<int> nums = {-10, -20, 5, 6, 3}; // Пример массива
    int result = maxProduct(nums);
    cout << "Максимальное произведение двух чисел массива: " << result << endl;
    return 0;
}
