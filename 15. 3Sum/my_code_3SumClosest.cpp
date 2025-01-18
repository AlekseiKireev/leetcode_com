class Solution {
public:

    vector<vector<int>>  threeSum(vector<int>& nums, int target = 0) {
        
        vector<vector<int>> Triplets;

        sort(nums.begin(), nums.end());
        const int SIZE = nums.size();

        for(int i = 0; i <= SIZE - 3; ++i){

            if(i > 0 && nums[i] == nums[i - 1]){ // статистика для nums[i] была собрана при обработке nums[i - 1] -- нет смысла вновь анализировть это число
                continue;
            }

            int k = SIZE - 1;
            int j = i + 1;
            while(j < k){
                
                int Sum3 = nums[i] + nums[j] + nums[k]; 
                if((Sum3 == target && Triplets.empty()) || (Sum3 == target && Triplets.back() != vector<int>{nums[i], nums[j], nums[k]})){
                    Triplets.push_back({nums[i], nums[j], nums[k]});
                }

                (Sum3 < target) ? ++j : --k;
                             
            }
        }

        return Triplets; 
    }

};
