class Solution {
public:
    int compress(vector<char>& chars) {

        // искомое
        int NewLength = 0;

        for(int i = 0; i < chars.size() ; ++i){

            char prev_char = chars[i]; 
            chars[NewLength] = prev_char;

            // CountRepeat -- количество повторяющихся символов prev_char, которые расположены в диапозоне [i, j] : i <= j
            int CountRepeat = 1; // 1, так как учитываем prev_char
            ++NewLength; // инкрементируем, так как учитываем prev_char

            // обновление CountRepeat
            while(i+1 < chars.size() && prev_char == chars[i+1]){
                
                ++CountRepeat;
                ++i;
                
            }

            // используем тот факт, что |substr| < |substr.size()|, где |*| -- функция, возвращающая длину строки *
            if(CountRepeat > 1){

                for(const char ch : to_string(CountRepeat)){
                    
                    chars[NewLength] = ch;
                    ++NewLength;
                    // equiv: chars[NewLength++] = ch;
                }

            }

        }

        return NewLength;
    }
};
