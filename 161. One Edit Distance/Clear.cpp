class Solution {
public:

    bool isOneEditDistance(string &s, string &t) {
        
        int SizeS = s.size();
        int SizeT = t.size();
        
        if(SizeT < SizeS){return isOneEditDistance(t,s);}
        if (SizeT - SizeS > 1) {return false;}

        for(int i = 0; i < SizeS; ++i){

            if(s[i] != t[i]){

                return (SizeT == SizeS+1) ? 
                    t.substr(i+1) == s.substr(i) // Delete t[i]
                : 
                    t.substr(i+1) == s.substr(i+1) // Replace s[i] with t[i]
                ;
            }
        }

        return SizeT == SizeS+1; // Insert t.back() at the end of s

    }
};
