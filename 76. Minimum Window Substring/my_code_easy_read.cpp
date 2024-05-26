class Solution {

private:

    // https://en.cppreference.com/w/cpp/language/ascii
    const int POWER_ENCODING = 128; // s and t consist of uppercase and lowercase English letters.

public:
    string minWindow(string& S, string& T) {

        // m == s.length n == t.length 1 <= m, n <= 10^5
        if(/*s.empty() || t.empty() ||*/ S.size() < T.size()){ // Input: s = "a", t = "aa" Output: ""
            return {};
        }

        vector<int> CharT_to_Count(POWER_ENCODING);
        for(const char ch : T){
            --CharT_to_Count[ch]; // если CharT_to_Count[ch] > 0, значит ch из t
        }

        int T_Size = T.size();

        // локальный максимум необходим ввиду того, чтобы гарантировать выполненеи RightPtr - LeftPtr < Substring_Size при T_Size == 0
        int Substring_Size = 10e5 + 1; // m == s.length n == t.length 1 <= m, n <= 10^5
        int Substring_LeftPtr = -1;

        for(int LeftPtr = 0, RightPtr = 0; RightPtr < S.size(); ++RightPtr){ // сдвиг правого указателя

            if(CharT_to_Count[S[RightPtr]] < 0){ // S[RightPtr] также существутет в T
                --T_Size;
            }
            ++CharT_to_Count[S[RightPtr]];

            for( ;T_Size == 0; ++LeftPtr){ // сдвиг левого указателя

                if(RightPtr - LeftPtr + 1 < Substring_Size){ // обновляем ответ
                    Substring_Size = RightPtr - LeftPtr + 1;
                    Substring_LeftPtr = LeftPtr;
                }

                if(CharT_to_Count[S[LeftPtr]] == 0){ // условие выхода из цикла
                    ++T_Size;
                }

                --CharT_to_Count[S[LeftPtr]];
            } // левый указатель

        }



        return Substring_LeftPtr == -1 ? "" : S.substr(Substring_LeftPtr, Substring_Size); 
        
    }
};
