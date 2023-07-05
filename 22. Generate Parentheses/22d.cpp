class Solution {
public:

    bool nextParentheses(vector<char>& cur) { // true - found next 
        int nOpening = 0;
        int nClosing = 0;
        for (int i = (int)cur.size() - 1; i >= 0; i--) {
            
            if (cur[i] == ')') {nClosing++;}
            else {
                assert(cur[i] == '(');
                ++nOpening;

                if (nClosing > nOpening) {

                    cur[i] = ')';
                    --nClosing;

                    while (nOpening > 0) {
                        ++i;
                        cur[i] = '(';
                        --nOpening;
                    }

                    while (nClosing > 0) {
                        ++i;
                        cur[i] = ')';
                        --nClosing;
                    }

                    return true;
                }
            }
        }
        return false;
    }



    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<char> cur;
        for (int i = 0; i < n; i++) {
            cur.push_back('(');
        }
        for (int i = 0; i < n; i++) {
            cur.push_back(')');
        }
        do {
            ans.push_back(string(cur.begin(), cur.end()));
        } while (nextParentheses(cur));
        return ans;
    }
};
