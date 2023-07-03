class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const auto it = unique(begin(nums), end(nums));
        nums.erase(it, end(nums));
        return nums.size(); 
    }
};

// более оптимальный аналог:
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        const auto it = unique(begin(nums), end(nums));
        return it - begin(nums);
        
    }
};

*/
