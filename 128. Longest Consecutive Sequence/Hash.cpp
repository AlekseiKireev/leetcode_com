class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        int LCS = 0;
        unordered_map<int, int> NumToRange;
        
        for (int n : nums) {

            if (NumToRange.count(n) == 0) {
                int left = NumToRange.count(n - 1) ? NumToRange[n - 1] : 0;
                int right = NumToRange.count(n + 1) ? NumToRange[n + 1] : 0;
                
                int SizeRange = left + right + 1;                
                
                LCS = max(LCS, SizeRange);
                
                NumToRange[n] = SizeRange;
                NumToRange[n - left] = SizeRange;
                NumToRange[n + right] = SizeRange;
            }

        }
        
        return LCS;
    }
};

/*
class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        int LCS = 0;
        std::unordered_map<int, int> NumToRange;
        
        for (int n : nums) {

            if (NumToRange.count(n) == 0) {
                int left = NumToRange.count(n - 1) ? NumToRange[n - 1] : 0;
                int right = NumToRange.count(n + 1) ? NumToRange[n + 1] : 0;
                
                int SizeRange = left + right + 1;                
                
                LCS = max(LCS, SizeRange);
                
                NumToRange[n] = SizeRange;
                NumToRange[n - left] = SizeRange;
                NumToRange[n + right] = SizeRange;
                cout << "num: " << n << ' ' << "range: " << SizeRange << '\n';
            }

        }

        cout << '\n';
        for(auto [num, range] : NumToRange){
            cout << "num: " << num << ' ' << "range: " << range << '\n';
        }
        
        return LCS;
    }
};
*/
/*
num: 100 range: 1
num: 4 range: 1
num: 200 range: 1
num: 1 range: 1
num: 3 range: 2
num: 2 range: 4

num: 2 range: 4
num: 3 range: 2
num: 1 range: 4
num: 200 range: 1
num: 4 range: 4
num: 100 range: 1
*/

/*
num: 0 range: 1
num: 3 range: 1
num: 7 range: 1
num: 2 range: 2
num: 5 range: 1
num: 8 range: 2
num: 4 range: 4
num: 6 range: 7
num: 1 range: 9

num: 1 range: 9
num: 6 range: 7
num: 4 range: 4
num: 8 range: 9
num: 5 range: 4
num: 2 range: 7
num: 7 range: 2
num: 3 range: 2
num: 0 range: 9
*/
