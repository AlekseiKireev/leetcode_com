class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {

        long long CntUniqInWindow = 0, MaxAffixSum = 0, AffixSum = 0;
        unordered_map<int, int> AffixSumToCount;

        for(int Right = 0, Left = 0; Right < nums.size(); ++Right){

            AffixSum += nums[Right];

            if(++AffixSumToCount[nums[Right]] == 1) { // подсчет уникальных элементов
                CntUniqInWindow++;
            }

            if(Right >= k){ // формирование окна длины k

                AffixSum -= nums[Left];

                if(--AffixSumToCount[nums[Left]] == 0) {CntUniqInWindow--;}

                Left++;
            }

            if(CntUniqInWindow >= m && Right - Left + 1 == k) { // формирование ответа
                MaxAffixSum = max(MaxAffixSum, AffixSum);
            }
        }
        return MaxAffixSum;
    }
};
