class Solution {
public:

    //  p == Angr == Anagram
    vector<int> findAnagrams(string S, string Angr) {
        
        int S_len = S.size();
        int Angr_len = Angr.size();

        /*
        20 / 65 testcases passed
        s = "aaaaaaaaaa"
        p = "aaaaaaaaaaaaa"
        */

        if(S_len < Angr_len){return {};} // необходимо для 20 / 65 testcases passed


        vector<int> CharSToCount(26, 0); // == window
        vector<int> CharAngrToCount(26, 0); 

        for(int i = 0; i < Angr_len; ++i){
            // s and p consist of lowercase English letters.
            ++CharSToCount[S[i] - 'a'];
            ++CharAngrToCount[Angr[i] - 'a'];
        }


        vector<int> Idxs;

        if(CharSToCount == CharAngrToCount){Idxs.push_back(0);}
        
        for(int i = Angr_len; i < S_len; ++i){

            --CharSToCount[S[i-Angr_len]-'a'];
            ++CharSToCount[S[i]-'a'];

            if(CharSToCount == CharAngrToCount){Idxs.push_back(i-Angr_len + 1);}
        }

        return Idxs;
    }
};
