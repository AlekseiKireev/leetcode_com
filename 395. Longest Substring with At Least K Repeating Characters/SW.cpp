class Solution {
public:
    int longestSubstring(const string& str, int k) {
        
        int maxUniqueCharacters = unordered_set<char>  {str.begin(), str.end()}.size();
        int longest = 0;

        for (int targetUnique = 1; targetUnique <= maxUniqueCharacters; ++targetUnique) {
            vector<int> charFrequency(128, 0);            
            
            int currentUnique = 0;
            int atLeastKCount = 0; // количество не менее K

            for (int left = 0, right = 0; right < str.size(); ) {

                // expand the sliding window
                if (currentUnique <= targetUnique) {

                    char rightChar = str[right];
                    if (charFrequency[rightChar] == 0) {
                        ++currentUnique;
                    }
                    ++charFrequency[rightChar];

                    if (charFrequency[rightChar] == k) {
                        ++atLeastKCount;
                    }
                    ++right;

                // shrink the sliding window    
                } else {

                    char leftChar = str[left];
                    if (charFrequency[leftChar] == k) {
                        --atLeastKCount;
                    }
                    --charFrequency[leftChar];

                    if (charFrequency[leftChar] == 0) {
                        --currentUnique;
                    }
                    
                    ++left;
                }

                if (currentUnique == targetUnique && currentUnique == atLeastKCount) {
                    longest = max(longest, right - left);
                }
                
            }
        }

        return longest;
    }

};
