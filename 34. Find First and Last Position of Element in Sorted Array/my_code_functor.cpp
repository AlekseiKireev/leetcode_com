class Solution {

private:

    int BinarySearch(const vector<int>& nums, const int target, function<int (int,int)> Operator, const bool LowerBound){

        int LeftBorder = -1;
        int RightBorder = nums.size();

        while(1 != RightBorder - LeftBorder){
                        
            assert(LeftBorder < RightBorder);
            
            int Mid = (LeftBorder + RightBorder) / 2;
            Operator(nums[Mid], target) ? LeftBorder = Mid : RightBorder = Mid;
        }

        if(LowerBound){ // инварианты: nums[LeftBorder] < target, target <= nums[RightBorder]  
            return ((nums[RightBorder] != target) ? -1 : RightBorder);
        } // инварианты: nums[LeftBorder] <= target, target < nums[RightBorder] 
        return ((nums[LeftBorder] != target) ? -1 : LeftBorder);
    }

public:

    vector<int> searchRange(vector<int>& nums, int target) {
        
        if( nums.empty() || target < nums.front() || nums.back() < target){return {-1,-1};}
        
        const int FirstIdx = BinarySearch(nums, target, less<int>(), 1); //  <
        if(FirstIdx == -1){return {-1,-1};}

        return { // https://en.cppreference.com/w/cpp/utility/functional
            
            FirstIdx, //  <
            BinarySearch(nums, target, less_equal<int>(),0) // <=
        };
        
    }

};
