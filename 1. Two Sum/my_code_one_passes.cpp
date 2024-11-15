class Solution {
public:

vector<int> twoSum(const vector<int>& nums, int target) {

    unordered_map<int, int> NumbToIdx;

    for (int idx = 0; idx < nums.size(); ++idx) {
               
        const int complement = target - nums[idx];
        // NumbToIdx[nums[idx]] = idx; // будет ошибка, например, на тесте: Input nums = [3,2,4] target = 6   Output [0,0] Expected [1,2]
        
        if (NumbToIdx.count(complement)) { 
            return { NumbToIdx[complement], idx };
        }
        
        NumbToIdx[nums[idx]] = idx; 

    }
    return {};

}

};
