const int FASTIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (true) {
            while (i < j && !isalnum((unsigned char)s[i])) {
                i++;
            }
            while (i < j && !isalnum((unsigned char)s[j])) {
                j--;
            }
            if (i < j) {
                if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
                    return false;
                }
                i++;
                j--;
            }
            else {
                return true;

            }
        }
    }
};

