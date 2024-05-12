class Solution {
public:
    bool isAnagram(string_view s, string_view t) {

        if (s.size() != t.size()) {return false;}

        const int power_English_alphabet = 26;
        array<int, power_English_alphabet> CharAngr_To_Count;
        CharAngr_To_Count.fill(0);

        for(int i = 0; i < s.size();++i){
            
            ++CharAngr_To_Count[s[i] - 'a'];
            --CharAngr_To_Count[t[i] - 'a'];
            
        }

        for(int i = 0; i < power_English_alphabet;++i){
            if(CharAngr_To_Count[i] != 0){return false;}
            }

        return true;
    }
};
