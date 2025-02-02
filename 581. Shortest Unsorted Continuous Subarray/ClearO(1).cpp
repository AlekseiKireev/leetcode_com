class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int RightPtr = -1;
        int LeftPtr = -1;

        int ExtremeMaxFront = nums.front();
        int ExtremeMinBack  = nums.back();
        for(int i = 0; i < nums.size(); ++i){

            ExtremeMaxFront = max(ExtremeMaxFront, nums[i]);
            if(nums[i] != ExtremeMaxFront){RightPtr = i;}
            
            ExtremeMinBack = min(ExtremeMinBack, nums[nums.size() - 1 - i]);
            if(nums[nums.size() - 1 - i] != ExtremeMinBack){LeftPtr = nums.size() - 1 - i;}


        }

        if(RightPtr == -1){return 0;}
        return RightPtr - LeftPtr + 1;

    }
};
