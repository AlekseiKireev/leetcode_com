class Solution {


unordered_set<string>buffer;
public:

    vector<string> removeInvalidParentheses(string Str) {
        
        removeHelper(Str, 0, 0, '(', ')');
        return {buffer.begin(), buffer.end()};
    }

private:
    void removeHelper(string Str,  int RightPtr, int LeftPtr, const char openParen, const char closedParen) {

        int numOpenParen = 0, numClosedParen = 0;
        for (int Right = RightPtr; Right < Str.length(); Right++) {

            if (Str[Right] == openParen)   {numOpenParen++;}
            if (Str[Right] == closedParen) {numClosedParen++;}

            if (numClosedParen - 1 == numOpenParen) { 

                for (int Left = LeftPtr; Left <= Right; Left++) {
                    
                    if (Str[Left] == closedParen ) {
                        removeHelper(Str.substr(0, Left) + Str.substr( Left + 1, Str.length() ), Right, Left, openParen, closedParen);
                    }
                }

                return;
            }
        } // numClosedParen <= numOpenParen

        string reversed = Str;
        reverse(reversed.begin(), reversed.end());
        if (openParen == '(') {
            removeHelper(reversed, 0, 0, ')', '(');
        } else {
            buffer.insert(reversed);
        }

    }
};
