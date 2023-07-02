class Solution {
public:
    int compress(vector<char>& chars) {

        // искомое
        int NewLength = 0;

        for(int i = 0; i < chars.size() ; ++i){

            char prev_char = chars[i]; 
            chars[NewLength] = prev_char;

            // count -- количество повторяющихся символов prev_char, которые расположены в диапозоне [i, j] : i <= j
            int count = 1; // 1, так как учитываем prev_char
            ++NewLength; // инкрементируем, так как учитываем prev_char


            while(i+1 < chars.size() && prev_char == chars[i+1]){
                
                ++count;
                ++i;
                
            }


            if(count > 1){

                for(const char ch : to_string(count)){
                    
                    chars[NewLength] = ch;
                    ++NewLength;
                    // equiv: chars[NewLength++] = ch;
                }

            }

        }

        return NewLength;
    }
};
