class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        
        int MinSize = nums.size() + 1;
        int SumBuff = 0;
        for(int Left = 0,  Right = 0; Right < nums.size(); ++Right){

            SumBuff += nums[Right];

            for(; SumBuff >= target; ++Left){

                MinSize = min(MinSize, Right- Left + 1);
                SumBuff -= nums[Left];
            }
        }
        
        return MinSize == nums.size() + 1 ? 0 : MinSize;

    }
};
