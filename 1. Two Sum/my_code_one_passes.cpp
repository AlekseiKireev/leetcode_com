class Solution {
public:

vector<int> twoSum(const vector<int>& nums, int target) {

    unordered_map<int, int> NumbToIdx;

    for (int idx = 0; idx < nums.size(); ++idx) {
               
        const int complement = target - nums[idx];

        if (NumbToIdx.count(complement) && NumbToIdx[complement] != idx) {
            return { NumbToIdx[complement], idx };
        }
        
        NumbToIdx[nums[idx]] = idx;

    }
    return {};

}

};
