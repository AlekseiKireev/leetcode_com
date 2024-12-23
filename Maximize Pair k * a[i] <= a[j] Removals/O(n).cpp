#include <iostream>
#include <vector>

int maxRemovedElements(const std::vector<int>& a, int k) {
    int n = a.size();
    int i = 0;
    int j = n - 1;
    int removedCount = 0;

    while (i < j) {
        if (k * a[i] <= a[j]) {
            removedCount += 2;
            ++i;
            --j;
        } else {
            --j;
        }
    }

    return removedCount;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    int k = 2;
    int result = maxRemovedElements(a, k);
    std::cout << "Максимальное количество удаленных чисел: " << result << std::endl;
    return 0;
}
