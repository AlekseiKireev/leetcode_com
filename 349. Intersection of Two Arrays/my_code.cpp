class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){return intersection(nums2, nums1); }
        assert(nums1.size() <= nums2.size());

        unordered_set<int> Numbers = {make_move_iterator(nums1.begin()), make_move_iterator(nums1.end())};

        vector<int> intersection; intersection.reserve(Numbers.size());
        
        for(const int num : nums2){
            if(Numbers.count(num)){
                Numbers.erase(num);
                intersection.push_back(num);
            }
        }

        intersection.shrink_to_fit();
        return intersection;
    }
};
