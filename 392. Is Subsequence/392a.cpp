class Solution {
public:
    bool isSubsequence(const string& sub, const string& s) {
        if (sub.empty()) {
            return true;
        }
        int i = 0;
        for (char c : s) {
            if (c == sub[i]) {
                i++;
                if (i == (int)sub.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
