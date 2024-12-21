#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countPairsWithSum(const vector<int>& a, int target) {
    unordered_map<int, int> NumToCount; // Хранит количество вхождений чисел
    int count = 0;

    for (int num : a) {
        int complement = target - num; // Вычисляем дополнение

        // Если дополнение уже есть в хеш-таблице, увеличиваем счетчик пар
        if (NumToCount[complement] > 0) {
            count += NumToCount[complement];
        }

        // Увеличиваем частоту текущего числа
        NumToCount[num]++;
    }

    return count;
}

int main() {
    vector<int> a = {1, -1, 2, -2, 3, -3, 4, -4};
    int target = 0;
    int result = countPairsWithSum(a, target);
    cout << "Количество пар с суммой " << target << ": " << result << endl;
    return 0;
}
