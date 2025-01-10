/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int IdxOnCompressStr = 0;

        for(int IdxOnOldStr = 0; IdxOnOldStr < chars.size(); ){
            
            const char CurChar = chars[IdxOnOldStr];
            chars[IdxOnCompressStr] = CurChar;
            ++IdxOnCompressStr;

            int CountPepeat = 0;
            for(; IdxOnOldStr < chars.size() && CurChar == chars[IdxOnOldStr]; ++IdxOnOldStr){
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
