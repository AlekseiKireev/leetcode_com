class Solution {
public:
    int strStr(string haystack, string needle) {
        
        const int IDX = haystack.find(needle);
        return ((string::npos == IDX) ? -1: IDX);

    }
};
