class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> NumToIdx;

        for(int i = 0; i < nums.size(); ++i){

            // nums[i] == nums[j] and abs(i - j) <= k.
            if(NumToIdx.count(nums[i]) // --> exist nums[j]
            &&
            (i - NumToIdx[nums[i]] <= k)
            ){                
                return true;                
            }
            
            NumToIdx[nums[i]] = i;

        }

        return false;

    }
};
