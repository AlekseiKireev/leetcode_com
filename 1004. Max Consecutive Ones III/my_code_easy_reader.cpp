class Solution {

private:

    // https://github.com/SkosMartren/leetcode_com/tree/main/485.%20Max%20Consecutive%20Ones
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int Ans = 0;
        int CurrentSum = 0;
        for(int num : nums){
            if(num == 1){
                ++CurrentSum;
            }else{ // num == 0
                Ans = max(Ans, CurrentSum);
                CurrentSum = 0; // ex: [1,1,0,1,1,1]
            }
        }

        return max(Ans, CurrentSum); // ex: [1,1,1,1,1]

    }

public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {
        
        if(CountUpdZero == 0){return findMaxConsecutiveOnes(nums);}

        int Ans = 0;

        for(int RightPtr = 0, LeftPtr = 0; RightPtr < nums.size() ; ++RightPtr){

            if(nums[RightPtr] == 0){
                --CountUpdZero;                
            }

            for(; CountUpdZero == -1; ++LeftPtr){
                if(nums[LeftPtr] == 0){++CountUpdZero;}
            } // после выхода из цикла CountUpdZero >= 0

            // RightPtr указывает либо на flip'нутый элемент (обращенный в 1) либо на 1
            Ans = max(Ans, RightPtr - LeftPtr + 1); // "+1" можно понять на основе "My ex 2"
        }

        return Ans;

    }
};
/* working!
class Solution {

public:

    int longestOnes(vector<int>& N, int k) {
        
        int Ans = 0;

        int CountFlipZero = 0;

        for(int L = 0, R = 0; R < N.size(); ++R){
            
            CountFlipZero += (N[R] == 0);

            for(;CountFlipZero == k + 1; ++L){
            
                CountFlipZero -= (N[L] == 0);            
            }

            Ans = max(Ans, R - L + 1);
        }

        return Ans;
    }

};
*/
