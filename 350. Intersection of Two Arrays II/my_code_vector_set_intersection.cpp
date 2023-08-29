class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection;
        intersection.reserve(min(nums1.size(), nums2.size()));

        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
                          std::back_inserter(intersection));

        intersection.shrink_to_fit();
        return intersection;

    }
};
