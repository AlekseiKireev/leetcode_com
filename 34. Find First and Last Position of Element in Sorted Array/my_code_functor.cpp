class Solution {

private:

    int BinarySearch(const vector<int>& nums, const int target, function<int (int,int)> Operator, const bool LowerBound){

        int RightBorder = -1;
        int LeftBorder = nums.size();

        while(1 != LeftBorder - RightBorder){
                        
            assert(RightBorder < LeftBorder);
            
            int Mid = (RightBorder + LeftBorder) / 2;
            Operator(nums[Mid], target) ? RightBorder = Mid : LeftBorder = Mid;
        }

        if(LowerBound){ // инварианты: nums[RightBorder] < target, nums[LeftBorder] >= target
            return ((nums[LeftBorder] != target) ? -1 : LeftBorder);
        } // инварианты: nums[RightBorder] <= target, nums[LeftBorder] > target
        return ((nums[RightBorder] != target) ? -1 : RightBorder);
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
/*
Для простоты положим, что target существует в nums
Инвариантный оператора для lower_bound: <
*/
