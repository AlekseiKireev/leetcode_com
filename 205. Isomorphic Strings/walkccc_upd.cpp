class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        vector<int> StoId(128,-1);
        vector<int> TtoId(128,-1);

        for(int i = 0; i < s.size(); ++i){
            
            if(StoId[s[i]] !=TtoId[t[i]]){return false;}

            StoId[s[i]] = i;
            TtoId[t[i]] = i;
            
        }

        return true;
    }
};
