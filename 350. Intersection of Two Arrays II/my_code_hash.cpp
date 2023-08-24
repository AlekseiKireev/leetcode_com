class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){return intersect(nums2, nums1);}

        assert(nums1.size() <= nums2.size());

        unordered_map<int, int> NumToCount;

        for(const int num : nums1){++NumToCount[num];}

        vector<int> intersection; intersection.reserve(nums1.size());

        for(const int num : nums2){
            
            if(NumToCount.find(num) != NumToCount.end() && NumToCount[num] > 0){

                intersection.push_back(num); // "you may return the result in any order."
                --NumToCount[num];
            }
            
            
        }

        intersection.shrink_to_fit();
        return intersection;
    }
};
