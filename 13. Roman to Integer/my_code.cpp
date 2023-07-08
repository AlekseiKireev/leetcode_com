class Solution {
public:
    int romanToInt(string_view s) { 

        unordered_map<char, int> romanToValue = {
           {'I', 1},
           {'V', 5},
           {'X', 10},
           {'L', 50},
           {'C', 100},
           {'D', 500},
           {'M', 1000}
           };

        int prev = romanToValue[s.front()];
        int ans = 0;

        for(const char ch : s){
            
            const int val = romanToValue[ch];
            
            ans += val;
            
            if(prev < val){ans -= 2 * prev;}

            prev = val;
        }

        return ans;
    }
} ;
