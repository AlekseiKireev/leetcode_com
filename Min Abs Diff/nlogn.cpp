#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <ranges>

int find_min_abs_difference(std::vector<int>& A, std::vector<int>& B) {
    std::ranges::sort(A);
    std::ranges::sort(B);
    
    int i = 0, j = 0;
    long long min_diff = std::numeric_limits<long long>::max();
    
    while (i < A.size() && j < B.size()) {
        min_diff = std::min(min_diff, static_cast<long long>(std::abs(static_cast<long long>(A[i]) - static_cast<long long>(B[j]))));
        if(min_diff == 0){return 0;)
        // Двигаем указатель на массиве с меньшим значением
        (A[i] < B[j]) ? ++i : ++j;
    }
    
    return static_cast<int>(min_diff);
}

int main() {
    std::vector<int> A = {10, 0, 2};
    std::vector<int> B = {5, 100, 12};
    
    std::cout << "Минимальная разница: " << find_min_abs_difference(A, B) << std::endl;
    
    return 0;
}
