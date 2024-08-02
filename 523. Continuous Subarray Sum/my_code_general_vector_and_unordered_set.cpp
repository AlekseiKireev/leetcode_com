class Solution {

/*
PrefixSumModK[n] - PrefixSumModK[m] = {nums[m] + ... + nums[n]} ModK : m < n
*/

public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        vector<int> PrefixSumModK; PrefixSumModK.reserve(nums.size() + 1);
        PrefixSumModK.push_back(0);

        long long CurSumModK = 0;
        for(int num : nums){
            CurSumModK = (CurSumModK + num % k + k) % k;
            PrefixSumModK.push_back(CurSumModK);
        }

        unordered_set<int> Buffer;
        for(int i = 2; i < PrefixSumModK.size(); ++i){

            Buffer.insert(PrefixSumModK[i-2]); 

            if(Buffer.count(PrefixSumModK[i])) {
                return true;
            }

        }

        return false;
    }
};
