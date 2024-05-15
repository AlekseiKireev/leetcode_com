class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans; 

        for(int RightPtr = 0; RightPtr < nums.size(); ++RightPtr){
            
            int LeftPtr = RightPtr;

            for(;RightPtr+1 < nums.size() && nums[RightPtr] == nums[RightPtr+1] - 1; ++RightPtr);

            if(LeftPtr == RightPtr){
                ans.push_back(to_string(nums[LeftPtr])); 
            }else{
                ans.push_back(to_string(nums[LeftPtr]) + "->" + to_string(nums[RightPtr])); 
            }
        }

        return ans;
    }
};
