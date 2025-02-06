#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

struct PairHash {
    
    size_t operator()(const pair<size_t, size_t>& pair) const {
        return pair.first ^ pair.second;
    }
};

int countSubarraysWithSubsequence(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    unordered_set<pair<int, int>, PairHash> IdxUniqueSybarrays;

    for (int l = 0; l < n; ++l) {
        int cnt = 0; // Количество совпавших элементов из b
        for (int r = l; r < n; ++r) {
            if (a[r] == b[cnt]) {
                ++cnt;
            } /*обнулять надо?*/
            /*else{cnt = 0;}*/
            
            if (cnt == m) {
                // Для каждой найденной правой границы r добавляем все возможные левые границы
                for (int j = 0; j <= l; ++j) {
                    IdxUniqueSybarrays.emplace(j, r);
                }

            }
        }
    }

    return IdxUniqueSybarrays.size();
}

int main() {
    vector<int> a = {1, 2, 3, 1, 42, 2, 3};
    vector<int> b = {1, 2};
    int result = countSubarraysWithSubsequence(a, b);
    cout << "Result: " << result << endl; // Ожидаемый результат: 11
    return 0;
}
