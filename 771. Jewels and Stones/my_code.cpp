class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        // если не помнишь про 'z' - 'A' + 1 можно использовать array от мощности кодировки, в ascii это 128
        // 'z' - 'A' + 1 <-- https://en.cppreference.com/w/cpp/language/ascii <-- https://www.utf8-chartable.de/
        vector<bool> JewelToCount('z' - 'A' + 1, false); // https://en.cppreference.com/w/cpp/container/vector_bool
        for(const char jewel : jewels){ // All the characters of jewels are unique.
            JewelToCount['z' - jewel] = true;
        }
        
        int CountStones = 0;

        for(const char stone : stones){
            CountStones += JewelToCount['z' - stone];
        }
        
        return CountStones;

    }
};
