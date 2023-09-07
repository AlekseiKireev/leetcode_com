class Solution {
public:
    vector<string> summaryRanges(const vector<int>& nums) {

        vector<string> ans;

        for (int i = 0; i < nums.size(); ++i) {

            const int start_ranges = nums[i];

            // while (i + 1 < nums.size() && nums[i + 1]  - nums[i] == 1) { ++i; } // error:
            //  nums[i] < nums[i+1] --> в 1 + nums[i] переполнения не будет, в то
            // время как в nums[i + 1]  - nums[i]  будет, например 
            // Runtime Error 24 / 32 testcases passed nums = [-2147483648,-2147483647,2147483647]
            // при подсчете 2147483647 - (-2147483647)
            // правильнее даже будет так: 
            // while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1) { ++i; }
            // <-->
            // for (;i + 1 < nums.size() && nums[i + 1]  - 1 == nums[i]; ++i);
            while (i + 1 < nums.size() && nums[i + 1] == 1 + nums[i]) { ++i; }

            if (start_ranges != nums[i]) {
                ans.push_back(to_string(start_ranges) + "->" + to_string(nums[i]));
            }
            else {
                ans.push_back(to_string(start_ranges));
            }

        }

        return ans;
    }

};
