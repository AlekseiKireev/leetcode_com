class Solution {
public:

    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) {
            return 0;
        }

        int haystackLen = haystack.length();
        int needleLen = needle.length();

        if (haystackLen < needleLen) {
            return -1;
        }

        for (int i = 0; i <= haystackLen - needleLen; ++i) {
            int j = 0;
            
            for (; j < needleLen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == needleLen) {
                return i;
            }
        }

        return -1;
    }

};
