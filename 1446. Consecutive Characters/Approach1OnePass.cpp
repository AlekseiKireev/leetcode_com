class Solution {
public:
    int maxPower(const string& s) {
        
        if(s.empty()){return 0;}

        int count = 1;
        int maxCount = 1;
        char previous = s.front();
      
        for (size_t i = 1; i < s.size(); ++i) {
          
            char c = s[i];
            if (c == previous) {
                count++;
            } else {
                count = 1;
                previous = c;
            }
          
            maxCount = max(maxCount, count);
        }
      
        return maxCount;
    }
};
