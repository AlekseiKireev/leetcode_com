class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> answer(2); // " return a list answer of size 2"

        // https://en.cppreference.com/w/cpp/iterator/move_iterator
        set<int> set1{make_move_iterator(nums1.begin()), make_move_iterator(nums1.end())};
        set<int> set2{make_move_iterator(nums2.begin()), make_move_iterator(nums2.end())};

        // https://en.cppreference.com/w/cpp/algorithm/set_difference --> "Copies the elements from the sorted range"
        set_difference(set1.begin(), set1.end(),
                        set2.begin(), set2.end(),
                        std::back_inserter(answer.front()));

        set_difference(set2.begin(), set2.end(),
                        set1.begin(), set1.end(),
                        std::back_inserter(answer.back()));

        return answer;
    }
};
