class Solution {

private:

static const int ALPHABET_SIZE = 26;

public:
    bool checkInclusion(string_view Angr, string_view Str) {
        
        array<int, ALPHABET_SIZE> DataAngr; DataAngr.fill(0); // <-- "s1 and s2 consist of lowercase English letters."
        for(const char ch : Angr){++DataAngr[ch - 'a'];}

        int CountCharAngrInWindow = 0;
        for(int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr){ // move RightPtr

            if(--DataAngr[Str[RightPtr] - 'a'] >= 0){++CountCharAngrInWindow;}

            while(CountCharAngrInWindow == Angr.size()){

                if(CountCharAngrInWindow == RightPtr - LeftPtr + 1){ /* совпали оба условия, отвечаю-я за анаграмму:                
                                                                        1. Размер окна равен размеру анаграммы 
                                                                        2. В окне находятся все символы, из которых состоит анаграмма
                                                                     */
                    return true;
                }

                if(++DataAngr[Str[LeftPtr++] - 'a'] > 0){ // условие выхода из цикла
                    --CountCharAngrInWindow;
                }
            }

        }

        return false;
    }
};
