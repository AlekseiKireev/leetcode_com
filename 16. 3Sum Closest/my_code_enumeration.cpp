class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int Closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() - 2; ++i){

            for(int j = i + 1; j != nums.size() - 1; ++j){
                
                const int TwoSum = nums[i] + nums[j];
                
                for( int k = j + 1; k < nums.size(); ++k){
                
                    if(nums[k] + TwoSum == target){return target;}
                    
                    if(abs(Closest - target) > abs(nums[k] + TwoSum - target)){
                        Closest = nums[k] + TwoSum;
                    }
                    
                }
            }            
        }

        return Closest;
    }
};
