class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1 = {make_move_iterator(nums1.begin()), make_move_iterator(nums1.end())};
        unordered_set<int> set2 = {make_move_iterator(nums2.begin()), make_move_iterator(nums2.end())};

        vector<vector<int>> answer(2);
        answer.front().reserve(set1.size());
        answer.back().reserve(set2.size());

        for(const auto num : set1){
            if(set2.count(num) == 0){
                answer.front().push_back(num);
            }
        }

        for(const auto num : set2){
            if(set1.count(num) == 0){
                answer.back().push_back(num);
            }
        }        

        answer.front().shrink_to_fit();
        answer.back().shrink_to_fit();
        return answer;

    }
};
