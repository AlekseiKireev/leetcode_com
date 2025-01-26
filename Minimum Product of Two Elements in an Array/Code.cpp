#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int findMinProduct(const vector<int>& nums) {
    if (nums.size() < 2) {
        throw invalid_argument("Array must have at least two elements.");
    }

    // Инициализируем минимальные и максимальные значения
    int min1 = max(nums[0], nums[1]);
    int min2 = max(nums[0], nums[1]);
    int max1 = min(nums[0], nums[1]);
    int max2 = min(nums[0], nums[1]);

    // Одним проходом по массиву находим два минимальных и два максимальных числа
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

    // Считаем варианты
    int product1 = min1 * max1; // есть положительные и отрицательные числа
    int product2 = min1 * min2; // все числа положительные 
    int product3 = max1 * max2; // все числа отрицательные

    // Возвращаем минимальное из возможных произведений
    return min({product1, product2, product3});
}

int main() {
    vector<int> nums = {3, -1, -7, 4, 2, -5};
    try {
        int result = findMinProduct(nums);
        cout << "Minimum product: " << result << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
