class Solution {

public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
        const int SIZE = nums.size();
        vector<int> answer(SIZE);


        int CountZero = 0;
        int IdxZero = -1;

        for(int i = 0; i < SIZE; ++i){
            
            if(nums[i] == 0){
                ++CountZero;
                if(CountZero == 2){return answer;}
                IdxZero = i;
            }            

        }

        if(CountZero == 1){
            nums[IdxZero] = 1;
            answer[IdxZero] = accumulate(nums.begin(), nums.end(), 1, multiplies<int>()); // https://en.cppreference.com/w/cpp/algorithm/accumulate
            return answer;
        }


        const long long product_nums = accumulate(nums.begin(), nums.end(), 1, multiplies<int>()); // https://en.cppreference.com/w/cpp/algorithm/accumulate

        for(int i = 0; i < SIZE; ++i){
            answer[i] = product_nums / nums[i];
        }

        return answer;
    }

};
