class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> MAX(nums.size()), MIN(nums.size()); 

        MAX[0] = nums[0];
        MIN.back()= nums.back();

        for(int i = 1; i < nums.size(); ++i){
            MAX[i] = max(MAX[i - 1], nums[i]);
        }

        for(int i = nums.size() - 2; i >= 0; --i){
            MIN[i] = min(MIN[i + 1], nums[i]);
        }

        
        int RightBorder = -1;
        for(int i = nums.size() - 1; i >= 0; --i){

            if(nums[i] != MAX[i]){
                RightBorder = i;
                break;
            }

        }        

        if(RightBorder == -1){return 0;} // nums is sorted
        int LeftBorder = -1;
        for(int i = 0; i < nums.size(); ++i){

            if(nums[i] != MIN[i]){
                LeftBorder = i;
                break;
            } 

        }

        return RightBorder - LeftBorder + 1;
    }
};
