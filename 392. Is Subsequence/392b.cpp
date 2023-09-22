const int ZERO = []() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class Solution {
public:
    bool isSubsequence(const string& sub, const string& s) {
        if (sub.empty()) {
            return true;
        }
        const int NOT_FOUND = -1;
        vector < vector < int>> next(
            s.size() + 1, vector<int>('z' - 'a' + 1, NOT_FOUND));
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }
        int subPos = 0;
        int sPos = 0;
        while (true) {
            sPos = next[sPos][sub[subPos] - 'a'];
            if (sPos == NOT_FOUND) {
                return false;
            }
            subPos++;
            if (subPos == (int)sub.size()) {
                return true;
            }
            sPos++;
        }
    }
};
