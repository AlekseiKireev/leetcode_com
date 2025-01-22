class Solution {

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

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<vector<int>, vector<string>, VectorHash> SortStrToAnagrams;


        for (const string& str : strs) {
            vector<int> freq = getFrequencyVector(str); // Вычисляем вектор частот
            SortStrToAnagrams[freq].push_back(str); 
        }

        vector<vector<string>> ans;ans.reserve(SortStrToAnagrams.size());
        for(auto [Key, VectorAnagrams] : SortStrToAnagrams){
            ans.push_back(move(VectorAnagrams));
        }

        return ans;

    }
};
