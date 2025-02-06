#include <iostream>
#include <vector>

using namespace std;

int countSubarraysWithSubsequence(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    int total = 0, previous = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] != b[0]) continue;  // Ищем первое совпадение с b[0]
        
        int cur = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] == b[cur]) {
                ++cur;
                if (cur == m) {  // Полностью нашли b в a[i:j]
                    total += (i + 1 - previous) * (n - j);
                    break;
                }
            }
        }
        previous = i + 1;  // Обновляем previous после завершения поиска
    }

    return total;
}

int main() {
    vector<int> a = {1, 2, 3, 1, 42, 2, 3};
    vector<int> b = {1, 2};

    cout << countSubarraysWithSubsequence(a, b) << endl;  // Ожидаемый ответ: 11
    return 0;
}
