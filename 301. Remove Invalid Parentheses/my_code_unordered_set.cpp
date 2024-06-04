class Solution {


unordered_set<string>buffer;
public:

    vector<string> removeInvalidParentheses(string s) {
        
        removeHelper(s, 0, 0, '(', ')');
        return {buffer.begin(), buffer.end()};
    }

private:
    void removeHelper(string s,  int iStart, int jStart, const char openParen, const char closedParen) { // " const char openParen, const char closedParen" по сути нужны для removeHelper(reversed, 0, 0, ')', '(');

        int numOpenParen = 0, numClosedParen = 0;
        for (int i = iStart; i < s.length(); i++) {

            if (s[i] == openParen)   {numOpenParen++;}
            if (s[i] == closedParen) {numClosedParen++;}

            if (numClosedParen - 1 == numOpenParen) { 

                for (int j = jStart; j <= i; j++) { // знак равенства нужен для "Wrong Answer 28 / 127 Input s = ")(" Use Testcase Output [] Expected [""]"
                    
                    if (s[j] == closedParen ) {
                        removeHelper(s.substr(0, j) + s.substr( j + 1, s.length() ), i, j, openParen, closedParen);
                    }
                }

                return;
            }
        } // numClosedParen <= numOpenParen

        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if (openParen == '(') {
            removeHelper(reversed, 0, 0, ')', '(');
        } else {
            buffer.insert(reversed);
        }

    }
};
