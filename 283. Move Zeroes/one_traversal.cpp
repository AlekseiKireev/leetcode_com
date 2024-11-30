/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums, int val = 0) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != val) { // если заменить на "==", то val перенесется в префикс
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};
