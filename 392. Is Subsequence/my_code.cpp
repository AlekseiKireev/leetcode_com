class Solution {
public:
    bool isSubsequence(string_view s, string_view t) {
        
        if (s.empty()) {
            return true;
        }        
        
        if(s.size() > t.size() || t.empty() /*!s.empty() == true ввиду прощлого if*/ ){return false;}
        
        int S_Idx = 0;
        for(int T_Idx = 0; T_Idx < t.size(); ++T_Idx){
            
            S_Idx += (s[S_Idx]  == t[T_Idx]);
            if(S_Idx == s.size()){return true;}
        }
        
        return false;
    }
};
