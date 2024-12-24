#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> minSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        result.reserve(nums.size() + 1 - k);
        std::deque<int> windowIndices; // Дека для хранения индексов элементов

        for (int i = 0; i < nums.size(); ++i) {
            // Удаляем все элементы из конца дека, которые больше текущего элемента
            while (!windowIndices.empty() && nums[windowIndices.back()] >= nums[i]) {
                windowIndices.pop_back();
            }

            // Добавляем текущий индекс в деку
            windowIndices.push_back(i);

            // Удаляем устаревшие элементы из начала дека
            if (windowIndices.front() < i - k + 1) {
                windowIndices.pop_front();
            }

            // Добавляем минимальный элемент в результат, если окно завершено
            if (i - k + 1 >= 0) {
                result.push_back(nums[windowIndices.front()]);
            }
        }

        return result;
    }
};

int main() {
    std::vector<int> nums = {10, 1, 2, 4, 7, 2};
    int k = 3;

    Solution solution;
    std::vector<int> result = solution.minSlidingWindow(nums, k);

    std::cout << "Минимумы в каждом окне длины " << k << ": ";
    for (int minVal : result) {
        std::cout << minVal << " ";
    }
    std::cout << std::endl;

    return 0;
}
