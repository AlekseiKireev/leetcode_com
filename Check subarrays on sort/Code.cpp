#include <iostream>
#include <vector>
using namespace std;

// Функция для вычисления префиксного массива
vector<int> computePrefix(const vector<int>& a) {
    int n = a.size();
    vector<int> pref(n, 0);
    for (int i = 1; i < n; ++i) {
        pref[i] = (a[i - 1] <= a[i]) ? 1 : 0;
        pref[i] += pref[i - 1];
    }
    return pref;
}

// Функция для проверки, отсортирован ли подотрезок
string isSortedSubarray(const vector<int>& pref, int l, int r) {
    --l; --r; // Преобразуем к 0-based индексам
    return (pref[r] - pref[l] == r - l) ? "Yes" : "No";
}

int main() {
    // Пример массива
    vector<int> a = {1, 2, 3, -1, 2, 3};
    vector<int> pref = computePrefix(a);

    // Пример запросов
    vector<pair<int, int>> queries = {{1, 3}, {2, 5}, {1, 6}, {4,6}};
    
    // Вывод результатов
    for (const auto& query : queries) {
        cout << "Query [" << query.first << ", " << query.second << "]: ";
        cout << isSortedSubarray(pref, query.first, query.second) << '\n';
    }

    return 0;
}
