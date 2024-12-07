class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int GlobalMin = INT_MAX;
        int Min2 = INT_MAX;

        int GlobalMax = INT_MIN;
        int Max2 = INT_MIN;
        int Max3 = INT_MIN;

        for (int num : nums) {

            if (num <= GlobalMin) {
                Min2 = exchange(GlobalMin, num);
            } else if (num < Min2) {
                Min2 = num;
            }

            if (GlobalMax <= num) {
                Max3 = exchange(Max2, exchange(GlobalMax, num));
            } else if (Max2 <= num) {
                Max3 = exchange(Max2, num);
            } else if (Max3 < num) {
                Max3 = num;
            }
        }

        return max(GlobalMax * GlobalMin * Min2, GlobalMax * Max2 * Max3);
    }
};
