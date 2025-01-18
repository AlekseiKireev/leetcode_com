class Solution {
    
    int SIZE;

    // https://github.com/AlKiAl/leetcode_com/tree/main/15.%203Sum
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> Triplets;

        for (int i = start; i <= SIZE - 3; ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            int k = SIZE - 1;
            int j = i + 1;
            while (j < k) {
                long long Sum3 = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                if ((Sum3 == target && Triplets.empty()) || 
                    (Sum3 == target && Triplets.back() != vector<int>{nums[i], nums[j], nums[k]})) {
                    Triplets.push_back({nums[i], nums[j], nums[k] });
                }
                (Sum3 < target) ? ++j : --k;
            }
        }

        return Triplets;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> Quadruplets;

        sort(nums.begin(), nums.end());
        SIZE = nums.size();

        for (int l = 0; l <= SIZE - 4; ++l) {
            if (l > 0 && nums[l] == nums[l - 1]) {
                continue;
            }

            vector<vector<int>> Triplets = threeSum(nums, l + 1, target - nums[l]);

            for (auto& triplet : Triplets) {
                triplet.push_back(nums[l]);
                Quadruplets.push_back(move(triplet));
            }
        }

        return Quadruplets;
    }
};
