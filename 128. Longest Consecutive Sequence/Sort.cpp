class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){return 0;}
        ranges::sort(nums);

        int LCS = 1; // Longest Consecutive Sequence
        int TmpLCS = 1;

        for(int i = 1; i < nums.size(); ++i){

            if(nums[i-1] != nums[i] ){ /* Input nums = [1,2,0,1] Expected 3 --> если соседние символы равны, ничего не делаем*/
                
            
                if(nums[i-1] == nums[i] - 1){
                    ++TmpLCS;
                }else { 
                    LCS = max(TmpLCS, LCS);
                    TmpLCS = 1;
                }

            }
            
        }

        return max(TmpLCS, LCS); // max на случай, если ни разу не вошли в "nums[i-1] != nums[i] - 1"
    }
};
