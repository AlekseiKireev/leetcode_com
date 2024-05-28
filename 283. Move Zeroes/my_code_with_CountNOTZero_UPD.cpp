class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int LastIdxNotZero = -1; // -1 как метка на случай, если nums состоит из нулей      

        for(int i = 0; i < nums.size(); ++i){

            if(nums[i] != 0){
                ++LastIdxNotZero;
                nums[LastIdxNotZero] = nums[i];
            }
        }

        if(LastIdxNotZero != -1){

            ++LastIdxNotZero; // теперь LastIdxNotZero указывает на начало окна нулей
            for(; LastIdxNotZero < nums.size(); ++LastIdxNotZero){

                nums[LastIdxNotZero] = 0;

            }

        }

    }
};
