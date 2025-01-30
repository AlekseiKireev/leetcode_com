#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    pair<int, int> maxTurbulenceSize(vector<int>& nums) {
        int ans = 1;
        int start = 0;
        int best_start = 0;
        int increasing = 1;
        int decreasing = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                increasing = decreasing + 1;
                decreasing = 1;
            } else if (nums[i] < nums[i - 1]) {
                decreasing = increasing + 1;
                increasing = 1;
            } else {
                increasing = 1;
                decreasing = 1;
                start = i;
            }

            if (max(increasing, decreasing) > ans) {
                ans = max(increasing, decreasing);
                best_start = start;
            }
        }

        return {best_start, ans};
    }
};
