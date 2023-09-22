const int ZERO = []() { // 557c.cpp

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class Solution {

    void reverse(string::iterator first, string::iterator after) { // 557d.cpp
        while (true) {
            if (first == after) {
                return;
            }
            --after;
            if (first == after) {
                return;
            }
            swap(*first, *after);
            ++first;
        }
    }


public:
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
