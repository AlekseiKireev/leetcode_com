class Solution {

private:

static const int ALPHABET_SIZE = 26; // <-- "s and p consist of lowercase English letters."

public:
    vector<int> findAnagrams(string_view Str, string_view Angr) {
        
        array<int, ALPHABET_SIZE> DataAngr; DataAngr.fill(0); 
        for(const char ch : Angr){++DataAngr[ch - 'a'];}

        vector<int> Idxs;

        int CountCharAngrInWindow = 0;я
        for(int LeftPtr = 0, RightPtr = 0; RightPtr < Str.size(); ++RightPtr){ // move RightPtr

            if(--DataAngr[Str[RightPtr] - 'a'] >= 0){ // Str[RightPtr] встречается в Angr
                ++CountCharAngrInWindow;
            }
            
            // Ex: "abcdefgtt" "t"
            for(;CountCharAngrInWindow == Angr.size(); LeftPtr++){// move LeftPtr
                
                if(RightPtr - LeftPtr + 1 == CountCharAngrInWindow){/* Совпали оба условия отвеча-е за то, что окно является анаграммой Angr:
                                                            1. Совпадают символы <-- "RightPtr - LeftPtr + 1 == CountCharAngrInWindow"
                                                            2. Совпадают длины  <-- "CountCharAngrInWindow == Angr.size()"
                                                          */
                    Idxs.push_back(LeftPtr);
                }

                // инкрементируем потому что заносим информацию и символе
                // строго больше нуля, потому что изначально заполнили все нулями <-- "array<int, ALPHABET_SIZE> DataAngr; DataAngr.fill(0);"
                if(++DataAngr[Str[LeftPtr] - 'a'] > 0){ // условие выхода из цикла: символ Str[LeftPtr] - 'a'] входит в Angr, поэтому LeftPtr должен указывать на него
                    --CountCharAngrInWindow;
                }
            }
            //assert(LeftPtr <= RightPtr); // error: "acdcaeccde" "c"
        }

        return Idxs;
    }
};

// более рациональный подсчет с точки зрения логики окна
/*
class Solution {
public:
    vector<int> findAnagrams(string_view s, string_view ang) {
        
        vector<int>  start_indices;

        // "s and p consist of lowercase English letters."
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
                    start_indices.push_back(LeftPtr);
                }

                if(--CharAngToCount[s[LeftPtr] - 'a'] < 0){ // сдвигаем левую границу, уменьшаем количество символов в окне
                    --CountCharsAngInWindow;
                }                
            }
        }

        return start_indices;
    }
};
*/
