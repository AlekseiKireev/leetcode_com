#include <iostream>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

class Solution {
public:
    pair<int, int> maxLengthSubarray(const vector<int>& nums, function<bool(int, int)> comp) {
        if (nums.empty()) return {-1, -1};

        int maxLength = 1;
        int currentLength = 1;
        int maxStartIndex = 0;
        int currentStartIndex = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (comp(nums[i-1], nums[i])) {
                currentLength++;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    maxStartIndex = currentStartIndex;
                }
            } else {
                currentLength = 1;
                currentStartIndex = i;
            }
        }
        return {maxStartIndex, maxLength};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 4, 7};
    
    // For increasing sequence
    auto incResult = solution.maxLengthSubarray(nums, less<int>());
    cout << "Longest increasing subarray starts at index: " << incResult.first
         << " with length: " << incResult.second << endl;

    // For decreasing sequence
    auto decResult = solution.maxLengthSubarray(nums, greater<int>());
    cout << "Longest decreasing subarray starts at index: " << decResult.first
         << " with length: " << decResult.second << endl;

    return 0;
}
// подзадача без поиска индексов: 
/*
class Solution {
public:
    int maxLengthSubarray(const vector<int>& nums, function<bool(int, int)> comp) {
        if (nums.empty()) return 0;

        int maxLength = 1;
        int currentLength = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (comp(nums[i-1], nums[i])) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 1;
            }
        }
        return maxLength;
    }
};
*/
/*
0,0 считается правильным ответом, если длина массива равен к 1. 
Если массив пустой надо возвращать -1,-1
*/
