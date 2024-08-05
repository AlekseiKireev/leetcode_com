class Solution {

bool CheckMonotonic(vector<int>& nums, auto comp){

    for(int i = 1; i < nums.size(); ++i){
        if(comp(nums[i-1], nums[i])){
            return false;
        }
    }

    return true;
}

public:
    bool isMonotonic(vector<int>& nums) {
        
        return (CheckMonotonic(nums, greater<int>()) || CheckMonotonic(nums, less<int>()));
    }
};
