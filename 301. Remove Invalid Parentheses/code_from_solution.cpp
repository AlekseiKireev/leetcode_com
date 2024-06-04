// https://leetcode.com/problems/remove-invalid-parentheses/solutions/75027/easy-short-concise-and-fast-java-dfs-3-ms-solution/

class Solution {

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s, ans, 0, 0, {'(', ')'});
        return ans;
    }

private:

    void remove(const string& s, vector<string>& ans, int last_i, int last_j, const vector<char>& par) {
        
        for (int stack = 0, i = last_i; i < s.size(); ++i) {

            if (s[i] == par[0]) stack++;
            if (s[i] == par[1]) stack--; // ')'
            if (stack >= 0) {continue;}

            // удаляем закрывающую скобку!
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {

                    remove(s.substr(0, j) + s.substr(j + 1), ans, i, j, par);
                }
            }

            return;
        }

        string reversed = string(s.rbegin(), s.rend());
        if (par[0] == '(') { // finished left to right
            remove(reversed, ans, 0, 0, {')', '('});
        } else { // finished right to left
            ans.push_back(reversed);
        }
    }
};
