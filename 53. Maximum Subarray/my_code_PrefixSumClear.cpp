/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {

public:

    int maxSubArray(vector<int>& nums) {
        
        int PrefixSum = 0; 
        int MinPrefixSum = 0; 
        int MaxAffixSum = nums.front(); 

        for(int i = 0; i < nums.size(); ++i){ 
            
            PrefixSum += nums[i];

            MaxAffixSum = max(MaxAffixSum, PrefixSum - MinPrefixSum); 
            MinPrefixSum = min(MinPrefixSum, PrefixSum); 
        }

        return MaxAffixSum; 

    }
};
