class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> Triplets;
        if(nums.front() > 0 || nums.back() < 0){return Triplets;}

        for(int i = 0; i < nums.size() - 2; ++i){
            
            if(i > 0 && nums[i - 1] == nums[i]){ continue;} // while(i > 0 && i < nums.size() - 3 && nums[i-1] == nums[i]){++i;} // error!

            //___________________________________________________
            // optimization
            if(nums[i+2] +nums[i+1] + nums[i] > 0){return Triplets;}
            if(nums[nums.size() - 2] +nums[nums.size() - 1] + nums[i] < 0){continue;}
            //___________________________________________________

            int k = nums.size() - 1;
            for(int j = i + 1; j != k; ++j){
                
                const int Target = nums[i] + nums[j];
                if(Target > 0){break;}
                
                for(;j != k - 1 && nums[k] + Target > 0;--k); // после выхода из этого цикла в крайнем случае j = k - 1 -- крайнее значение, которое может достигаться индексом j
                
                if(nums[k] + Target == 0){Triplets.push_back({nums[i], nums[j], nums[k]});}

                for(; j != k - 1 && nums[j + 1] == nums[j]; ++j);
            }            
        }
        

        return Triplets;
    }
};
