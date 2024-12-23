#include <iostream>
#include <vector>
#include <algorithm>

int maxPairs(const std::vector<int>& a, int k) {
    int n = a.size();
    int i = 0;           // Указатель на начало массива
    int j = n / 2;       // Указатель на середину массива
    int pairs = 0;       // Счетчик пар

    while (i < n / 2 && j < n) {
        if (k * a[i] <= a[j]) {
            // Зачеркиваем пару
            ++pairs;
            ++i;
            ++j;
        } else {
            // Иначе увеличиваем только указатель j
            ++j;
        }
    }

    return pairs * 2; // Каждая пара удаляет 2 элемента
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    int k = 2;
    std::cout << "Максимальное количество удаленных чисел: " << maxPairs(a, k) << std::endl;
    return 0;
}
