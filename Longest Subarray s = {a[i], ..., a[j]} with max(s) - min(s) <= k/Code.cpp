#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int longestSubarrayWithLimit(const std::vector<int>& nums, int k) {
    std::deque<int> minDeque, maxDeque;
    int left = 0, maxLength = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // Обновляем дек для минимума
        while (!minDeque.empty() && nums[right] <= nums[minDeque.back()]) {
            minDeque.pop_back();
        }
        minDeque.push_back(right);

        // Обновляем дек для максимума
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
            maxDeque.pop_back();
        }
        maxDeque.push_back(right);

        // Проверяем условие разницы
        while (!minDeque.empty() && !maxDeque.empty() && left != right &&
               nums[maxDeque.front()] - nums[minDeque.front()] > k
               ) {
            ++left;

            // проверка индексов из minDeque/maxDeque на выход за границу [left, right]
            if (minDeque.front() < left) {
                minDeque.pop_front();
            }
            if (maxDeque.front() < left) {
                maxDeque.pop_front();
            }
        }

        // Обновляем максимальную длину
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {10, 1, 2, 4, 7, 2};
    int k = 5;
    std::cout << "Длина максимального подотрезка: " << longestSubarrayWithLimit(nums, k) << std::endl;
    return 0;
}
