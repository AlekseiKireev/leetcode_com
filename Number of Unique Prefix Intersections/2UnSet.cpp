#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> count_prefix_intersections(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_set<int> set_a, set_b;
    std::vector<int> result;
    int count = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        // Добавляем элементы в соответствующие множества
        bool new_in_a = set_a.insert(a[i]).second;
        bool new_in_b = set_b.insert(b[i]).second;

        // Проверяем пересечения
        if (set_a.count(b[i]) && new_in_b) {
            ++count;
        } 
        if (set_b.count(a[i]) && new_in_a) {
            ++count;
        }

        // Записываем количество пересечений
        result.push_back(count);
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
