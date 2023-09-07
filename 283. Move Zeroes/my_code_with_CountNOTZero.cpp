class Solution {
public:
void moveZeroes(vector<int>& nums) {

	int LastIdxNotZero = 0;

	for (int num : nums) {
		if (num != 0) {
			nums[LastIdxNotZero] = num;
			++LastIdxNotZero;
		}
	}

	for (; LastIdxNotZero < nums.size(); ++LastIdxNotZero) {
		nums[i] = 0;
	}
}
};
