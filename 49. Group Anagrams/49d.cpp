const int ZERO = []() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<char> key;
        for (const string& str : strs) {
            int histogram[26] = {};
            for (char c : str) {
                histogram[c - 'a']++;
            }
            key.clear();
            for (char c = 'a'; c <= 'z'; c++) {
                int count = histogram[c - 'a'];
                if (count > 0) {
                    key.push_back(c);
                }
                if (count > 1) {
                    assert(count < 256 * 256);
                    key.push_back(count >> 8);
                    key.push_back(count & 0xFF);
                }
            }
            groups[string(key.begin(), key.end())].push_back(str);
        }
        vector<vector<string>> ans;
        ans.reserve(groups.size());
        for (auto& kv : groups) {
            ans.push_back(move(kv.second));
        }
        return ans;
    }
};
