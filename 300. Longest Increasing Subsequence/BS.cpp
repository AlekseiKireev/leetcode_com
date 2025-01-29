class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seen;
        for (int num : nums) {
            if (seen.empty() || seen.back() < num) {
                seen.push_back(num);
            } else {
                auto it = ranges::lower_bound(seen, num); // Find the index of the first element >= num
                *it = num; // Replace that number with num
            }
        }
        return seen.size();
    }
};
