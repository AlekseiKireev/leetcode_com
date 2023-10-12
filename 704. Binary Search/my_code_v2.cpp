class Solution {

public:

    int search(vector<int>& nums, int target) {
        
        if(nums.empty() || target < nums.front() || nums.back() < target){return -1;}

        assert(nums.front() <= target && target <= nums.back());
        
        /* // Wrong Answer 31 / 47 testcases   Input nums = [2,5] target = 5 // при таких указателях не верно обрабатываются случаи с двумя элементами. Это можно исправить написав условие: while(0 <= RightBorder - LeftBorder ){ ... LeftBorder = Mid + 1; ... RightBorder = Mid - 1; 
        int LeftBorder = 0;
        int RightBorder = nums.size() - 1;
        */

        if(nums.front() == target){return 0;}
        if(nums.back() == target){return nums.size() - 1;}

        int LeftBorder = 0;
        int RightBorder = nums.size() - 1;

        while(2 != RightBorder - LeftBorder + 1){

            int Mid = LeftBorder + (RightBorder - LeftBorder) / 2;
            if(nums[Mid] == target){return Mid;}
            if(nums[Mid] < target){
               LeftBorder = Mid;
            }else{ // target <= nums[Mid] 
               RightBorder = Mid;
            }

        }

        return -1;
    }

};
