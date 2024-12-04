class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {

            auto it = ranges::lower_bound(res, nums[i]);

            if(it==res.end()) {
                res.push_back(nums[i]);
            }
            else {
                *it = nums[i];
            }
        }
        return res.size();
    }
};
