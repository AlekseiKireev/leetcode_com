class Solution {
public:
    int compress(vector<char>& chars) {
  
        int ans = 0;

        for(int i = 0; i < chars.size() ; ++i){
            
            int count = 1; // 1, так как учитываем prev_char
            char prev_char = chars[i]; 
            chars[ans] = prev_char;
            ++ans; // инкрементируем, так как учитываем prev_char


            while(i+1 < chars.size() && prev_char == chars[i+1]){
                
                ++count;
                ++i;
                
            }


            if(count > 1){

                for(const char ch : to_string(count)){
                    
                    chars[ans] = ch;
                    ++ans;
                    // equiv: chars[ans++] = ch;
                }

            }

        }

        return ans;
    }
};
