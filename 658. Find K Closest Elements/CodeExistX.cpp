#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
    // Найти индекс x с помощью бинарного поиска
    int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    // Два указателя: начнем с index и соседнего элемента
    int left = index;   // x гарантированно в массиве
    int right = index + 1;

    // Расширяем указатели до тех пор, пока не соберем k элементов
    while (right - left  != k) {
        if (left == 0) { // Если достигли начала массива
            ++right;
        } else if (right == arr.size()) { // Если достигли конца массива
            --left;
        } else {
            // Выбираем ближайший элемент к x
            if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
        }
    }


    return std::vector<int>(arr.begin() + left, arr.begin() + right);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    std::vector<int> result = findClosestElements(arr, k, x);

    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
