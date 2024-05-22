class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(move(s)); // а тут точно работает move? Найти пруф в документации!   

        string ans; ans.reserve(s.size());
        
        for(string buffer; ss >> buffer; ){
            reverse(buffer.begin(), buffer.end());
            ans += (move(buffer) + " ");

        }
        ans.pop_back();
        return ans;
    }
};
