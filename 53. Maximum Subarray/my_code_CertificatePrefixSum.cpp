// https://e-maxx.ru/algo/maximum_average_segment --> Алгоритм 1

class Solution {

public:

    int maxSubArray(vector<int>& nums) {

        int PrefixSum = 0; 
        int MinPrefixSum = 0; 

        int totalMax = nums.front(); // == MaxSuffixSum = sum{nums[j]} : LeftIdxMaxSuffixSum <= j <= RightIdxMaxSuffixSum

        int RightIdxMinPrefixSum = -1;

        int RightIdxMaxSuffixSum = 0;
        int LeftIdxMaxSuffixSum = 0;


        for(int i = 0; i < nums.size(); ++i){


            PrefixSum += nums[i];

            // totalMax = max(totalMax, PrefixSum - MinPrefixSum);
            if(totalMax < PrefixSum - MinPrefixSum){
                totalMax = PrefixSum - MinPrefixSum;
                RightIdxMaxSuffixSum = i;
                LeftIdxMaxSuffixSum = RightIdxMinPrefixSum + 1;
            }
            
            // MinPrefixSum = min(MinPrefixSum, PrefixSum); 
            if(MinPrefixSum > PrefixSum){
                MinPrefixSum = PrefixSum;
                RightIdxMinPrefixSum = i;
            }
            
        }

        totalMax = accumulate(nums.begin() + LeftIdxMaxSuffixSum, nums.begin() + RightIdxMaxSuffixSum + 1, 0); 
        return totalMax; 
    }
};
