class Solution {

public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
        const int SIZE = nums.size();
        vector<int> answer(SIZE, 1);
        
        /* 
        answer[i] = (prefix[i]) * (suffix[i]) --> При SIZE = 6:
        answer[0] = (1) * (nums[1] * nums[2] * nums[3] * nums[4] * nums[5] * 1)
        answer[1] = (1 * nums[0]) * (nums[2] * nums[3] * nums[4] * nums[5] * 1)
        answer[2] = (1 * nums[0] * nums[1]) * (nums[3] * nums[4] * nums[5] * 1)
        answer[3] = (1 * nums[0] * nums[1] * nums[2]) * (nums[4] * nums[5] * 1)
        answer[4] = (1 * nums[0] * nums[1] * nums[2] * nums[3]) * (nums[5] * 1)
        answer[5] = (1 * nums[0] * nums[1] * nums[2] * nums[3] * nums[4]) * (1)
        */

        for(int i = 1; i < SIZE; ++i){ // make product prefix
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for(int i = SIZE - 2; i >= 0 ; --i){  // make product suffix
            suffix *= nums[i + 1];
            answer[i] *= suffix;
        }

        return answer;
    }

};

/*
class Solution {

public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
        const int SIZE = nums.size();
        vector<int> answer(SIZE, 1);


        int CountZero = 0;
        int IdxZero = -1;

        for(int i = 1; i < SIZE; ++i){ // make product prefix
            
            if(nums[i - 1] == 0){
                ++CountZero;
                IdxZero = i - 1;
            }

            if(CountZero >= 2){return vector<int>(SIZE, 0);}


            answer[i] = answer[i - 1] * nums[i - 1];
        }

        if(CountZero == 1){
            answer.assign(SIZE, 0);
            nums[IdxZero] = 1;
            answer[IdxZero] = accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
            return answer;
        }

        int suffix = 1;
        for(int i = SIZE - 2; i >= 0 ; --i){  // make product suffix
            suffix *= nums[i + 1];
            answer[i] *= suffix;
        }

        return answer;
    }

};
*/
