#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findElementsNotInSecond(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::vector<int> result;
    int Ptr_1 = 0, Ptr_2 = 0;

    while (Ptr_1 < nums1.size() && Ptr_2 < nums2.size()) {
        if (nums1[Ptr_1] < nums2[Ptr_2]) {
            result.push_back(nums1[Ptr_1]);
            Ptr_1++;
        } else if (nums1[Ptr_1] == nums2[Ptr_2]) {
            Ptr_1++;
            Ptr_2++;
        } else {
            Ptr_2++;
        }
    }

    /* Если остались элементы в nums1, которые не были проверены, например:
    std::vector<int> nums1 = {1, 2, 3, 11};
    std::vector<int> nums2 = {4, 5};
    */
    
    while (Ptr_1 < nums1.size()) {
        result.push_back(nums1[Ptr_1]);
        Ptr_1++;
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
