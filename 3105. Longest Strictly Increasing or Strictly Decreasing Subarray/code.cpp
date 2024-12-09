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
        return {maxStartIndex, maxLength};
    }
    
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(maxLengthSubarray(nums, less<int>()).second
            ,
                    maxLengthSubarray(nums, greater<int>()).second
        );
    }
};
