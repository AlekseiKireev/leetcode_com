class Solution {

public:
    int maxSubArray(const vector<int>& a) {

        int CurrentMaxAffixSum = a[0];
        int TotalMaxAffixSum = a[0];

        for (size_t i = 1; i < a.size(); i++) {
            CurrentMaxAffixSum = max(CurrentMaxAffixSum + a[i], a[i]);
            TotalMaxAffixSum = max(TotalMaxAffixSum, CurrentMaxAffixSum);
        }

        return TotalMaxAffixSum;

    }
};
