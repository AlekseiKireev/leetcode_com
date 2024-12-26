class Solution {
public:
    int longestSubstring(const string& str, int k) {
        
        int maxUniqueCharacters = unordered_set<char>  {str.begin(), str.end()}.size();
        int longest = 0;

        /*
        Подстрока является допустимой, если каждый символ имеет частоту не менее k. 
        Основная идея заключается в том, чтобы найти все допустимые подстроки 
        с разным количеством уникальных символов и отследить максимальную длину. 
        */
        // Длина искомой подстроки будет содержать не более maxUniqueCharacters уник. символов
        // --> достаточно проверить частоты, содержащие не мене k уникальных символов 
        // из диапозона [1, maxUniqueCharacters] 
        for (int targetUniq = 1; targetUniq <= maxUniqueCharacters; ++targetUniq) {
            vector<int> charFrequency(128, 0);            
            
            int CntCurUnique = 0;
            int CntLetHavFreqSizeK = 0; // количество не менее K

            for (int left = 0, right = 0; right < str.size(); ) {

                // expand the sliding window
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

                // shrink the sliding window    
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

                // Окно состоящее из CntCurUnique уник. симво. которое содержит последовательность
                // как минимум из CntLetHavFreqSizeK повторя-я символов
                if (/*CntCurUnique == targetUniq && */CntCurUnique == CntLetHavFreqSizeK) {
                    longest = max(longest, right - left);
                }
                
            }
        }

        return longest;
    }

};
