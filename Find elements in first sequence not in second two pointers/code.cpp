#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findElementsNotInSecond(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            result.push_back(nums1[i]);
            i++;
        } else if (nums1[i] == nums2[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }

    // Если остались элементы в nums1, которые не были проверены
    while (i < nums1.size()) {
        result.push_back(nums1[i]);
        i++;
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {4, 5};

    std::vector<int> result = findElementsNotInSecond(nums1, nums2);

    std::cout << "Elements in the first sequence not in the second: ";
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
