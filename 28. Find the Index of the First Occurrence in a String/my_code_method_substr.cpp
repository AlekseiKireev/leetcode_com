class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack.size() < needle.size()){return -1;}
        if(haystack.size() == needle.size()){
            //return (needle == haystack) ? 0 : -1;
            return ((needle == haystack) - 1);
        }
        
        // i < haystack.size() - needle.size() + 1 // почему +1? По меньшей мере нужен для теста Input haystack = "abc" needle = "c"  Expected 2
        for(int i = 0; i < haystack.size() - needle.size() + 1; ++i){
            if(haystack.substr(i, needle.size()) == needle){return i;}
        }

        return -1;

    }
};
