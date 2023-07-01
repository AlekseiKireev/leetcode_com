class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        int i = nums.size() - 1;
        vector<int>  ans(nums.size());

        for(int l = 0, r = nums.size() - 1; l <= r;){ // l != r -- error!
            
            if(abs(nums[l]) > abs(nums[r])){

                ans[i] = nums[l] * nums[l];
                --i;
                ++l;

            }else{ // abs(nums[l]) <= abs(nums[r])
                ans[i] = nums[r] * nums[r];
                --i;
                --r;
                
            }
        }

        return ans;
    }
};
