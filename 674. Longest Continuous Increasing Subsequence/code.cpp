class Solution {

    pair<int, int> maxLengthSubarray(const vector<int>& nums, function<bool(int, int)> comp) {
        if (nums.empty()) return {-1, -1};

        int maxLength = 1;
        int currentLength = 1;
        int maxStartIndex = 0;
        int currentStartIndex = 0;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (comp(nums[i-1], nums[i])) {
                currentLength++;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    maxStartIndex = currentStartIndex;
                }
            } else {
                currentLength = 1;
                currentStartIndex = i;
            }
        }
        cout << maxLength <<'\n';
        return {maxStartIndex, maxLength};
    }

public:
    int findLengthOfLCIS(vector<int>& nums) {
        auto [maxStartIndex, maxLength] = maxLengthSubarray(nums, less<int>());
        return maxLength;
    }
};
