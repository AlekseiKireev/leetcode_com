class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack.size() < needle.size()){return -1;}

        const int IDX = haystack.find(needle); // https://en.cppreference.com/w/cpp/string/basic_string/find
        return ((string::npos == IDX) ? -1: IDX);

    }
};
