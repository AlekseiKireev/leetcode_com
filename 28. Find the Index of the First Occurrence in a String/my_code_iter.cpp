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

        for (int LeftPtr = 0; LeftPtr <= haystackLen - needleLen; ++LeftPtr) {
            int RightPtr = 0;
            
            for (; RightPtr < needleLen; ++RightPtr) {
                if (haystack[LeftPtr + RightPtr] != needle[RightPtr]) {
                    break;
                }
            }

            if (RightPtr == needleLen) {
                return LeftPtr;
            }
        }

        return -1;
    }

};
