class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        
        unordered_map<int, int> NumToCount;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int Complement = k - nums[i];

            if (NumToCount[Complement] > 0) {

                count++;
                NumToCount[Complement]--;
                
            } else {
                NumToCount[nums[i]]++;
            }
        }

        return count;
    }
};
