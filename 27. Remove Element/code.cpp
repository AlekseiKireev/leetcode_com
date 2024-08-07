class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int Idx = 0;

        for(int i = 0; i < nums.size();++i){

            if(nums[i] != val){
                swap(nums[Idx++], nums[i]);
                // nums[Idx++] = nums[i]; // good!
            }
        }

        return Idx;

    }
};
