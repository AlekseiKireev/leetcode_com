class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
               
        int i = nums.size() - 1;
        vector<int>  ans(nums.size());

        for(int LeftBorderWindow  = 0, RightBorderWindow  = nums.size() - 1; /*LeftBorderWindow <= RightBorderWindow*/ i>=0;--i){ // l != r -- error!
            
            if(abs(nums[LeftBorderWindow]) > abs(nums[RightBorderWindow])){ // локальный максимум в nums из диапозона индексов [LeftBorderWindow, RightBorderWindow] находится в крайнем левой стороне окна

                ans[i] = nums[LeftBorderWindow] * nums[LeftBorderWindow];
                ++LeftBorderWindow;

            }else{ // abs(nums[LeftBorderWindow ]) <= abs(nums[RightBorderWindow])
                
                ans[i] = nums[RightBorderWindow ] * nums[RightBorderWindow];
                --RightBorderWindow;
            }
            
        }

        return ans;
    }
};
