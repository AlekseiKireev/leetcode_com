/*
Time:O(n^2) 
Space:O(n)    
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) { // is true --> s == P*k : P is str
        
        int size = s.size();
        
        string postfix = s.substr(1, size-1); // строка без первого символа.
        string prefix = s.substr(0, size-1); //  строка без последнего символа.
        
        string sFold = postfix + prefix; // head + P*k' + tail : k' == (k-1)*2
        //string sFold = prefix + postfix; // P*k^ + tail + head + P*k^ : k^ == k-1
        return sFold.find(s) != string::npos;
    }
};
