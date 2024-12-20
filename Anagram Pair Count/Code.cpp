#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Хэш-функция для вектора
struct VectorHash {
    size_t operator()(const vector<int>& vec) const {
        size_t hash = 0;
        for (int num : vec) {
            hash ^= hash * 31 + num; // Простая комбинированная хэш-функция
        }
        return hash;
    }
};

// Функция для вычисления вектора частот букв
vector<int> getFrequencyVector(const string& str) {
    vector<int> freq(26, 0); // Вектор частот для 26 букв
    for (char c : str) {
        freq[c - 'a']++; // Увеличиваем частоту текущей буквы
    }
    return freq;
}

// Основная функция для подсчета количества пар
int countAnagramPairs(const vector<string>& strings) {
    unordered_map<vector<int>, int, VectorHash> freqMap; // Используем кастомный хэш
    int pairCount = 0;

    for (const string& str : strings) {
        vector<int> freq = getFrequencyVector(str); // Вычисляем вектор частот
        pairCount += freqMap[freq]; // Добавляем к числу пар количество уже найденных таких же векторов
        freqMap[freq]++; // Увеличиваем количество вхождений текущего вектора
    }

    return pairCount;
}

int main() {
    // Пример использования
    vector<string> strings = {"abc", "bca", "cab", "xyz", "zyx", "yxz", "aaa"};
    int result = countAnagramPairs(strings);
    cout << "Количество пар анаграмм: " << result << endl;
    return 0;
}
