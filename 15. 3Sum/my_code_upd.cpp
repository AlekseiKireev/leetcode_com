class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> Triplets;
        if(nums.front() > 0 || nums.back() < 0){return Triplets;}

        for(int i = 0; i < nums.size() - 2; ++i){
            
            while(i > 0 && ){}

            int k = nums.size() - 1;
            for(int j = 0; j < k; ++j){
                
                const int Target = nums[i] + nums[j];
                if(Target > 0){break;}


            }            
        }
        
    }
};
