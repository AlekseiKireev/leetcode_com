class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string doubled = s + s;
        // Функция substr(1, 2 * n - 2) берет подстроку длиной 2 * n - 2, начиная с индекса 1
        return doubled.substr(1, 2 * n - 2).find(s) != string::npos;
    }
};
