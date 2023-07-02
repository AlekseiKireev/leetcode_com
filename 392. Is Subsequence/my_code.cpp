class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int check_idx_s = 0;
        for(int i = 0; i< t.size();++i){
            
            if(s[check_idx_s]  == t[i]){++check_idx_s;}
            if(check_idx_s == s.size()){return true;}
        }
        if(check_idx_s == s.size()){return true;}
        return false;
    }
};
