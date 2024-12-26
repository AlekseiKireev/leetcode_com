class Solution {
public:
    int longestSubstring(const string& str, int k) {
        
        int maxUniqueCharacters = unordered_set<char>  {str.begin(), str.end()}.size();
        int longest = 0;

        for (int targetUniq = 1; targetUniq <= maxUniqueCharacters; ++targetUniq) {
            vector<int> charFrequency(128, 0);            
            
            int CntCurUnique = 0;
            int CntLetHavFreqSizeK = 0; 

            for (int left = 0, right = 0; right < str.size(); ) {

                if (CntCurUnique <= targetUniq) {

                    char rightChar = str[right];
                    if (charFrequency[rightChar] == 0) {
                        ++CntCurUnique;
                    }
                    ++charFrequency[rightChar];

                    if (charFrequency[rightChar] == k) {
                        ++CntLetHavFreqSizeK;
                    }
                    ++right;

                } else {

                    char leftChar = str[left];
                    if (charFrequency[leftChar] == k) {
                        --CntLetHavFreqSizeK;
                    }
                    --charFrequency[leftChar];

                    if (charFrequency[leftChar] == 0) {
                        --CntCurUnique;
                    }
                    
                    ++left;
                }

                if (CntCurUnique == CntLetHavFreqSizeK) {
                    longest = max(longest, right - left);
                }
                
            }
        }

        return longest;
    }

};
