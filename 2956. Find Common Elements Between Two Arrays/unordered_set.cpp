class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Ans(2);
        unordered_set<int> nums1_set = {nums1.begin(), nums1.end()};
        unordered_set<int> nums2_set = {nums2.begin(), nums2.end()};

        for(auto n1 : nums1){
            if(nums2_set.contains(n1)){
                Ans[0]++;
            }
        }
        for(auto n2 : nums2){
            if(nums1_set.contains(n2)){
                Ans[1]++;
            }
        }
        return Ans;
    }
};
