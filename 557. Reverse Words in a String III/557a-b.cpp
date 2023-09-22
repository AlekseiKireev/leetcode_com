class Solution {
public:
    // string reverseWords(string s) { // 557a.cpp
    string reverseWords(string& s) {
        string::iterator wordStart = s.begin();
        for (string::iterator wordEnd = s.begin(); wordEnd != s.end(); ++wordEnd) {
            if (*wordEnd == ' ') {
                reverse(wordStart, wordEnd);
                wordStart = wordEnd;
                ++wordStart;
            }
        }
        reverse(wordStart, s.end());
        return move(s);
    }
};
