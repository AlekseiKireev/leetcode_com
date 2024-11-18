/*
Time complexity: O(n*log(k)*word.size())
Space complexity: O(n)
*/
class Solution {


public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        if(words.size() == k){ // "k is in the range [1, The number of unique words[i]]"
            
            ranges::sort(words);
            return words;
        }        

        
        unordered_map<string, int> StringToCount;

        for(string& word : words){
            ++StringToCount[word];
        }


        vector<pair<int, string>> Buffer;
        Buffer.reserve(StringToCount.size());

        for(auto [str, cnt] : StringToCount){
            Buffer.push_back({cnt, move(str)});
        }

        // https://en.cppreference.com/w/cpp/algorithm/partial_sort -->
        // Given M as middle - first, N as last - first: 3,4) Approximately N ⋅ log ( M ) applications of the comparator comp.
        partial_sort(Buffer.begin(), Buffer.begin() + k, Buffer.end(),
                      [](const auto& data1, const auto& data2) {
                          return data1.first > data2.first // сортируем числа по убывания 
                          || 
                          (data1.first == data2.first && data1.second < data2.second) // при равинстве количества строк сортируем строки по возрастанию
                          ;}
                    );      


        vector<string> TopK; TopK.reserve(k);
        for(int i = 0; i < k;++i){
            TopK.push_back(move(Buffer[i].second));
        }

        return TopK;
    }
};
