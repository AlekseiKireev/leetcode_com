class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = {0, 0};

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for(auto x: nums1){
            if(binary_search(nums2.begin(), nums2.end(), x)){
                result[0] ++;
            }
        }

        for(auto x: nums2){
            if(binary_search(nums1.begin(), nums1.end(), x)){
                result[1] ++;
            }
        }

        return result;
    }
};
