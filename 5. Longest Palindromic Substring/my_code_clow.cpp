class Solution {
    bool isPalindrome(const string& S, int left, int right) {
        while (left < right) {
            if (S[left++] != S[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    string longestPalindrome(const string& s) {
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j > i; j--) {
                if (j - i + 1 <= maxLength) {
                    break;  // No need to continue, we won't find a longer palindrome.
                }
                
                if (isPalindrome(s, i, j)) {
                    int length = j - i + 1;
                    if (length > maxLength) {
                        start = i;
                        maxLength = length;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }
};
