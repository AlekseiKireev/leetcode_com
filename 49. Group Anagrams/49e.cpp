const int ZERO = []() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& str : strs) {
            int histogram[26] = {};
            for (char c : str) {
                histogram[c - 'a']++;
            }
            string key = "";
            for (char c = 'a'; c <= 'z'; c++) {
                int count = histogram[c - 'a'];
                if (count > 0) {
                    key += c;
                }
                if (count > 1) {
                    while (count > 0) {
                        int d = count % 10;
                        count /= 10;
                        key += (char)('0' + d);
                    }
                }
            }
            groups[key].push_back(str);
        }
        vector<vector<string>> ans;
        ans.reserve(groups.size());
        for (auto& kv : groups) {
            ans.push_back(move(kv.second));
        }
        return ans;
    }
};
