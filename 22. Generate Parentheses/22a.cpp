class Solution {
public:
    void generateParentheses(vector<char>& cur, int toOpen, int toClose, vector<string>& ans) {

        if (toOpen == 0 && toClose == 0) {
            ans.push_back(string(cur.begin(), cur.end()));
            return;
        }
        if (toOpen > 0) {
            cur.push_back('(');
            generateParentheses(cur, toOpen - 1, toClose + 1, ans);
            cur.pop_back();
        }
        if (toClose > 0) {
            cur.push_back(')');
            generateParentheses(cur, toOpen, toClose - 1, ans);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        vector<char> cur;

        generateParentheses(cur, n, 0, ans);

        return ans;
    }
};
