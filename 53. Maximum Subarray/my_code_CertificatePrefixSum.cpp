// https://e-maxx.ru/algo/maximum_average_segment --> Алгоритм 1

class Solution {

public:

    int maxSubArray(vector<int>& nums) {

        int PrefixSum = 0; 
        int MinPrefixSum = 0; 

        // если написать 0, это будет ошибка на массиве отрицательных чисел!
        int MaxAffixSum = nums.front(); // == MaxSuffixSum = sum{nums[j]} : LeftIdxMaxSuffixSum <= j <= RightIdxMaxSuffixSum

        int RightIdxMinPrefixSum = -1;

        int RightIdxMaxSuffixSum = 0;
        int LeftIdxMaxSuffixSum = 0;


        for(int i = 0; i < nums.size(); ++i){


            PrefixSum += nums[i];

            // MaxAffixSum = max(MaxAffixSum, PrefixSum - MinPrefixSum);
            if(MaxAffixSum < PrefixSum - MinPrefixSum){
                MaxAffixSum = PrefixSum - MinPrefixSum;
                RightIdxMaxSuffixSum = i;
                LeftIdxMaxSuffixSum = RightIdxMinPrefixSum + 1;
            }
            
            // MinPrefixSum = min(MinPrefixSum, PrefixSum); 
            if(MinPrefixSum > PrefixSum){
                MinPrefixSum = PrefixSum;
                RightIdxMinPrefixSum = i;
            }
            
        }

        assert(MaxAffixSum == accumulate(nums.begin() + LeftIdxMaxSuffixSum, nums.begin() + RightIdxMaxSuffixSum + 1, 0) );
        return MaxAffixSum; 
    }
};

/*
class Solution {

pair<int,int> findMaxSubArrayBounds(const vector<int>& nums){
    int tempStart = 0;
    int currentSumAffix = 0;
    int minSumAffix = 0;
    int maxSum = nums[0]; // если написать 0, это будет ошибка на массиве отрицательных чисел!
    int Start = 0, End = 0;

    for(int i = 0; i < nums.size(); ++i){
        currentSumAffix += nums[i];

        if(currentSumAffix - minSumAffix > maxSum){
            maxSum = currentSumAffix - minSumAffix;
            Start = tempStart;
            End = i;
        }

        if(currentSumAffix < minSumAffix){
            minSumAffix = currentSumAffix;
            tempStart = i + 1;
        }
    }

    return {Start, End};
}

public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // For empty input, return 0 (or another appropriate value)
        }
        
        auto [L, R] = findMaxSubArrayBounds(nums);
        return accumulate(nums.begin() + L, nums.begin() + R + 1, 0);
    }
};
*/
