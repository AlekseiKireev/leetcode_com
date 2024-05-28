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

            // move LeftPtr
            for(;CountCharAngrInWindow == Angr.size(); LeftPtr++){ // никаких досрочных выходов из цикла быть не должно, ибо надо в DataAngr заполнить то, что отняли в "--DataAngr[Str[RightPtr] - 'a']"

                if(CountCharAngrInWindow == RightPtr - LeftPtr + 1){ /* совпали оба условия, отвечаю-я за анаграмму:                
                                                                        1. Размер окна равен размеру анаграммы  <-- "CountCharAngrInWindow == Angr.size()"
                                                                        2. В окне находятся все символы, из которых состоит анаграмма <-- "CountCharAngrInWindow == RightPtr - LeftPtr + 1"
                                                                     */
                    return true;
                }

                if(++DataAngr[Str[LeftPtr] - 'a'] > 0){ // условие выхода из цикла: Str[LeftPtr] является символом, который находится в Angr
                    --CountCharAngrInWindow;
                }
            }

        }

        return false;
    }
};
/*
class Solution {

private:

static const int ALPHABET_SIZE = 26;

public:
    bool checkInclusion(string_view ang, string_view s) {
          vector<int>  start_indices;

        array<int,26> CharAngToCount; CharAngToCount.fill(0);
        for(char ch : ang){
            --CharAngToCount[ch - 'a'];
        }

        int CountCharsAngInWindow = 0;
        for(int RightPtr = 0, LeftPtr = 0; RightPtr < s.size(); ++RightPtr){

            if(++CharAngToCount[s[RightPtr] - 'a'] <= 0){ // сдвигаем правую границу, увпличиваем количетсво символов в окне
                ++CountCharsAngInWindow;
            }

            for(; CountCharsAngInWindow == ang.size(); ++LeftPtr){

                if(RightPtr - LeftPtr + 1 == ang.size()){
                    return true;
                }

                // количество символов НЕ из анаграммы > 0, если s[LeftPtr] из анаграммы, то CharAngToCount[s[LeftPtr] - 'a'] = 0, так как CountCharsAngInWindow == ang.size()
                if(--CharAngToCount[s[LeftPtr] - 'a'] < 0){ // сдвигаем левую границу, уменьшаем количество символов в окне
                    --CountCharsAngInWindow;
                }                
            }
        }

        return false;
    }
};
*/
