class Solution {
public:
    int maxPower(const std::string& s) {
      
        int count = 0;
        int maxCount = 0;
        char previous = ' ';
      
        for (size_t i = 0; i < s.length(); ++i) {
          
            char c = s[i];
            if (c == previous) {
                // if same as previous one, increase the count
                count++;
            } else {
                // else, reset the count
                count = 1;
                previous = c;
            }
          
            maxCount = std::max(maxCount, count);
        }
      
        return maxCount;
    }
};
