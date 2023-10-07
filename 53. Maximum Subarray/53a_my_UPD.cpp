class Solution {

public:
    int maxSubArray(const vector<int>& nums) {

        // "nums.front()" существует ввиду "1 <= nums.length <= 10^5"
        int CurrentMaxAffixSum = nums.front();
        int TotalMaxAffixSum = nums.front();

        for (size_t i = 1; i < nums.size(); i++) {
            CurrentMaxAffixSum = max(CurrentMaxAffixSum + nums[i], nums[i]);
            TotalMaxAffixSum = max(TotalMaxAffixSum, CurrentMaxAffixSum);
        }

        return TotalMaxAffixSum;

    }
};

/*

*/
