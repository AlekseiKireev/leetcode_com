class Solution {


public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        if(words.size() <= k){
            
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

        partial_sort(Buffer.begin(), Buffer.begin() + k, Buffer.end(),
                      [](const auto& data1, const auto& data2) {
                          return data1.first > data2.first // сортируем числа по убывания 
                          || 
                          (data1.first == data2.first && data1.second < data2.second) // при равинстве чисел сортируем строки по возрастанию
                          ;}
                    );      


        vector<string> TopK; TopK.reserve(k);
        for(int i = 0; i < k;++i){
            TopK.push_back(move(Buffer[i].second));
        }

        return TopK;
    }
};
