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

	for (int i = LastIdxNotZero; i < nums.size();++i) {
		nums[i] = 0;
	}
}
};
