class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        // https://en.cppreference.com/w/cpp/language/ascii
        vector<bool> JewelToCount('z' - 'A' + 1, false);
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
