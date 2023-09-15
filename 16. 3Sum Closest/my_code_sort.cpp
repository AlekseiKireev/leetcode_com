class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        const int SIZE = nums.size();

        for(int i = 0; i < SIZE - 2; ++i){

            if(i > 0 && nums[i] == nums[i - 1]){ // статистика для nums[i] была собрана при обработке nums[i - 1] -- нет смысла вновь анализировть это число
                continue;
            }

            int k = SIZE - 1;
            int j = i + 1;
            while(j < k){
                
                int Sum3 = nums[i] + nums[j] + nums[k]; // Sum3 --> target 
                if(Sum3 == target){return target;}

                // "расстояние" между target и Sum3 меньше, нежели между target и closest
                if(abs(Sum3 - target) < abs(closest - target)){closest = Sum3;}

                (Sum3 < target) ? ++j : --k;
            }
        }

        return closest; // "расстояние" между closest и target минимально
    }

};
