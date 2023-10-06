class Solution {

public:
    int maxSubArray(const vector<int>& nums) {

        int CurrentMaxAffixSum = nums[0];
        int TotalMaxAffixSum = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            CurrentMaxAffixSum = max(CurrentMaxAffixSum + nums[i], nums[i]);
            TotalMaxAffixSum = max(TotalMaxAffixSum, CurrentMaxAffixSum);
        }

        return TotalMaxAffixSum;

    }
};
