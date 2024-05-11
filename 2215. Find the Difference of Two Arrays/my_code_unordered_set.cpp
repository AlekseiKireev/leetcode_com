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
/*
class Solution {
public:
    // Returns the elements in the first arg nums1 that don't exist in the second arg nums2.
    vector<int> getElementsOnlyInFirstList(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> onlyInNums1;
        
        // Store nums2 elements in an unordered set. 
        unordered_set<int> existsInNums2;
        for (int num : nums2) {
            existsInNums2.insert(num);
        }
        
        // Iterate over each element in the list nums1.
        for (int num : nums1) {
            if (existsInNums2.find(num) == existsInNums2.end()) {
                onlyInNums1.insert(num);
            }
        }
        
        // Convert to vector.
        return vector<int> (onlyInNums1.begin(), onlyInNums1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {getElementsOnlyInFirstList(nums1, nums2), getElementsOnlyInFirstList(nums2, nums1)};
    }
};
*/
