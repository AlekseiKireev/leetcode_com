class Solution {

public:
    int maxSubArray(const vector<int>& a) {

        int CurrentTotalMaxSuffixSum = a[0];
        int TotalMaxSuffixSum = a[0];

        for (size_t i = 1; i < a.size(); i++) {
            CurrentTotalMaxSuffixSum = max(CurrentTotalMaxSuffixSum + a[i], a[i]);
            TotalMaxSuffixSum = max(TotalMaxSuffixSum, CurrentTotalMaxSuffixSum);
        }

        return TotalMaxSuffixSum;

    }
};
