class Solution {

public:

    int search(vector<int>& nums, int target) {
        
        if(nums.empty() || target < nums.front() || nums.back() < target){return -1;}

        assert(nums.front() <= target && target <= nums.back());

        int LeftBorder = 0;
        int RightBorder = nums.size() - 1;

        while(0 <= RightBorder - LeftBorder ){

            int Mid = LeftBorder + (RightBorder - LeftBorder) / 2;
            if(nums[Mid] == target){return Mid;}
            if(nums[Mid] < target){
               LeftBorder = Mid + 1;
            }else{ // target < nums[Mid] 
               RightBorder = Mid - 1;
            }

        }

        return -1;
    }

};
