class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //std::vector<int> merged; merged.reserve(nums1.size() + nums2.size());
        std::vector<int> merged(nums1.size() + nums2.size());

        // Сливаем отсортированные векторы
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

        int total = merged.size();

        if (total % 2 == 1) {
            // If the total number of elements is odd, return the middle element as the median.
            return (merged[total / 2]);
        } else {
            // If the total number of elements is even, calculate the average of the two middle elements as the median.
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (middle1 + middle2) / 2.0;
        }
    }
};
