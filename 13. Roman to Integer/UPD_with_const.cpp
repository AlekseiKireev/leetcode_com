class Solution {
public:
    int romanToInt(string_view s) { 

       const unordered_map<char, int> romanToValue = {
           {'I', 1},
           {'V', 5},
           {'X', 10},
           {'L', 50},
           {'C', 100},
           {'D', 500},
           {'M', 1000}
           };

       int ans = 0;
       int prey = romanToValue.at(s[0]); 

       for (const char c : s) {
           const int value = romanToValue.at(c);
         
           if (value <= prey) { 
               ans += value;
           } else {
               ans += value; 
               ans -= 2 * prey;
           }
           prey = value;
       }
       
       return ans;
    }
} ;
