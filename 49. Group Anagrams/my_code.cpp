class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> SortStrToAnagrams;
        

        for(string& str : strs){
            
            string CopyStr = str;
            sort(str.begin(), str.end());
            SortStrToAnagrams[str].push_back(move(CopyStr));
        }

        vector<vector<string>> ans;ans.reserve(SortStrToAnagrams.size());
        for(auto [Key, Anagrams] : SortStrToAnagrams){

            ans.push_back(move(Anagrams));
        }

        return ans;

    }
};
