const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {

// "Sort the words with the same frequency by their lexicographical order."
struct Data{

    int Count = 0;
    string Word = "";

};

public:
    vector<string> topKFrequent( vector<string>& words, int k) {

        if(words.size() <= k){
            
            ranges::sort(words);
            return words;
        }
        // можно ли отуверждать, что количество слов в words <= k ? <-- "k is in the range [1, The number of unique words[i]]"
        // поэтому можно спокойно обращаться по индексу в последнем цикле

        unordered_map<string, int> WordToIdxInBuffer; // хочу закрепить за каждой уникальной строкой из words индекс в Buffer
        vector<Data> Buffer(words.size() + 1);
        int IDX = 1; // начал с "1", так как operator[] для unordered_map по учолчанию создает значение равным 0
        
        for(const string& str : words){

            if(WordToIdxInBuffer[str] == 0){
                WordToIdxInBuffer[str] = IDX;
                Buffer[IDX] = {1, str};
                IDX++;

            }else{
                ++Buffer[WordToIdxInBuffer[str]].Count;
            }

        }


        // сортируем так, чтобы количество шло в порядке убывания, а строки в лексикографическом порядке в случае равного количества:
        // например, из "Example 1" --> Buffer = {{2, i}, {2, love}, {1, coding}, {1, leetcode}}
        sort(Buffer.begin(), Buffer.end(), 
        [](const Data& data1, const Data& data2){

            return data1.Count > data2.Count || (data1.Count == data2.Count && data1.Word < data2.Word); 
        }
        );

        Buffer.resize(WordToIdxInBuffer.size());

        /*
        
        for(auto [a, b] : Buffer){
            cout << a << ' ' << b << '\n';
        }
        */

        vector<string> FrequentStrings; FrequentStrings.reserve(k);
        for(int i = 0; i < k ; ++i){
            FrequentStrings.push_back(move(Buffer[i].Word));
        }

        return FrequentStrings;

    }
};
