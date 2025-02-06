#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> count_prefix_intersections(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_set<int> set_a, set_b;
    std::unordered_set<int> intersection_set; // Для хранения пересечений
    std::vector<int> result;

    for (size_t i = 0; i < a.size(); ++i) {
        // Добавляем элементы в соответствующие множества
        set_a.insert(a[i]);
        set_b.insert(b[i]);

        // Проверяем пересечения
        if (set_a.count(b[i]) > 0) {
            intersection_set.insert(b[i]); // Добавляем элемент в пересечения, если он уже есть в set_a
        }
        if (set_b.count(a[i]) > 0) {
            intersection_set.insert(a[i]); // Добавляем элемент в пересечения, если он уже есть в set_b
        }

        // Записываем количество уникальных пересечений
        result.push_back(intersection_set.size());
    }

    return result;
}

int main() {
    std::vector<int> a = {5, 1, 2, 3, 7, 1};
    std::vector<int> b = {1, 2, 1, 3, 0, 1};

    std::vector<int> answer = count_prefix_intersections(a, b);

    for (int x : answer) {
        std::cout << x << " ";
    }

    return 0;
}
