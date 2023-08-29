class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> answer(2); // " return a list answer of size 2"

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        const auto it_1 =  unique(nums1.begin(), nums1.end());
        const auto it_2 = unique(nums2.begin(), nums2.end());        

        // https://en.cppreference.com/w/cpp/algorithm/set_difference --> "Copies the elements from the sorted range"
        set_difference(nums1.begin(), it_1,
                        nums2.begin(), it_2,
                        std::back_inserter(answer.front()));

        set_difference(nums2.begin(), it_2,
                        nums1.begin(), it_1,
                        std::back_inserter(answer.back()));

        return answer;
    }
};
