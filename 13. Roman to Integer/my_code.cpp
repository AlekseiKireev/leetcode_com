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

       int ans = 0;
       int prey = romanToValue[s[0]]; 

       for (char c : s) {
           int value = romanToValue[c];
         
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
