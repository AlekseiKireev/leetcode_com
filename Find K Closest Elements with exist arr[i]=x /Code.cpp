#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> find_k_closest(const std::vector<int>& a, int index, int k) {
    int left_ptr = index - 1;
    int right_ptr = index + 1;

    for (int count = 1; count < k; count++) {
            if (left_ptr < 0 
                    || 
                (right_ptr < a.size() && a[right_ptr]  - a[index] <= a[index] - a[left_ptr])
            ) {
            right_ptr++;
        } else {
            left_ptr--;
        }
        
    }
    // надо от интервала (a.begin() + left_ptr, a.begin() + right_ptr) 
    // перейти к отрезку [a.begin() + left_ptr + 1, a.begin() + right_ptr - 1]
    return {a.begin() + left_ptr + 1, a.begin() + right_ptr}; 
    // возвращается полуинтервал [a.begin() + left_ptr + 1, a.begin() + right_ptr) ==
    // [a.begin() + left_ptr + 1, a.begin() + right_ptr - 1]
}

int main() {
    std::vector<int> arr = {1, 3, 7, 8, 9, 12};
    int index = 2; // Element at index 2 is 7
    int k = 4; // Number of closest elements to find

    std::vector<int> result = find_k_closest(arr, index, k);

    std::cout << "The " << k << " closest elements to " << arr[index] << " are: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
