class Solution {
public:
    pair<int, int> maxPower(const string& s) {
        if (s.empty()) return {0, -1};
        
        int count = 1, maxCount = 1;
        int leftIndex = 0, maxLeftIndex = 0;
        char previous = s.front();
        
        for (size_t i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (c == previous) {
                count++;
            } else {
                count = 1;
                previous = c;
                leftIndex = i;
            }
            
            if (count > maxCount) {
                maxCount = count;
                maxLeftIndex = leftIndex;
            }
        }
        
        return {maxCount, maxLeftIndex};
    }
};
