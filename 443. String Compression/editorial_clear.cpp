/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int IdxOnCompressStr = 0;

        for(int i = 0; i < chars.size(); ){
            
            const char CurChar = chars[i];
            chars[IdxOnCompressStr] = CurChar;
            ++IdxOnCompressStr;

            int CountPepeat = 0;
            for(; i < chars.size() && CurChar == chars[i]; ++i){
                ++CountPepeat;
            }

            if(CountPepeat > 1){

                for(char ch : to_string(CountPepeat)){

                    chars[IdxOnCompressStr] = ch;
                    ++IdxOnCompressStr;    

                }
            }

        }

        return IdxOnCompressStr; 
    }
};
