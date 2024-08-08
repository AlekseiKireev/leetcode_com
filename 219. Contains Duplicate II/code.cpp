class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> NumToCount;

        for(int i = 0; i < nums.size(); ++i){

            // nums[i] == nums[j] and abs(i - j) <= k.
            if(NumToCount.count(nums[i]) // --> exist nums[j]
            &&
            (i - NumToCount[nums[i]] <= k)
            ){                
                return true;                
            }
            
            NumToCount[nums[i]] = i;

        }

        return false;

    }
};
