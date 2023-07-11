class Solution {
public:

    int search(vector<int>& nums, int target) {

        // Find the insertion position `idx`.
        const int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        if (idx >= 0 && nums[idx] == target) {return idx;} 
        else {return -1;}    
    }

};
