class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(move(s));
        

        string ans;
        string buffer;
        while(ss >> buffer){
            reverse(buffer.begin(), buffer.end());
            ans += (move(buffer) + " ");

        }
        ans.pop_back();
        return ans;
    }
};
