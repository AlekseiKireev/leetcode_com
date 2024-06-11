class Solution {

pair<int, int> GetPtr(vector<int>& nums) {
    
    int maxSum = INT_MIN; // искомое!
    int currentSum = 0;
    int start = 0;
    int end = 0;
    int tempStart = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];
        
        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
        
        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }
    
    return {start, end};
}

public:
    int maxSubArray(vector<int>& nums) {
        
        auto [L, R] = GetPtr(nums);
        return accumulate(nums.begin() + L, nums.begin() + R + 1, 0);
        
    }
};
