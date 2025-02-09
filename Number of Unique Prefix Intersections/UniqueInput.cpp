#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> count_prefix_intersections(const std::vector<int>& a, const std::vector<int>& b) {
    std::unordered_map<int, int> freq;
    std::vector<int> result;
    int count = 0;

    for (size_t i = 0; i < a.size(); ++i) {
        if (++freq[a[i]] == 2) {
            ++count;
        }
        if (++freq[b[i]] == 2) {
            ++count;
        }

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
