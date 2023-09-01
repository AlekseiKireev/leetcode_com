class Solution {


public:

    vector<int> productExceptSelf(const vector<int>& nums) {
        
        const int SIZE = nums.size();

        /* answer[i] = (prefix[i]) * (suffix[i]) --> При SIZE = 6
        answer[0] = (1) * (answer[1] * answer[2] * answer[3] * answer[4] * answer[5])
        ...
        answer[3] = (1 * answer[0] * answer[1] * answer[2]) * (answer[4] * answer[5] * 1)
        ...
        answer[5] = (answer[0] *answer[1] * answer[2] * answer[3] * answer[4]) * (1)

        prefix.front() = 1
        suffix.back() = 1
        */
        vector<int> answer(SIZE);

        // prefix[i] = product(nums[k]) : 0 <= k <= i - 1, nums[i] == сепаратор, число которого не должно быть в answer[i]
        vector<int> prefix(SIZE, 1); // prefix[i] = prefix[i-1] * nums[i - 1]    : 1 <= i <= SIZE - 1

        // suffix[i] = product(nums[k]) : i + 1 <= k <= SIZE - 1, nums[i] == сепаратор, число которого не должно быть в answer[i]
        vector<int> suffix(SIZE, 1); // suffix[i] = suffix[i + 1] * nums[i + 1]  :  SIZE - 2 >= i >= 0
        
        for(int i = 1; i < SIZE; ++i){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }        

        for(int i = SIZE - 2; i >= 0; --i){
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }           

        for(int i = 0; i < SIZE; ++i){
            answer[i] = (prefix[i]) * (suffix[i]);
        }

        return answer;

    }

};
