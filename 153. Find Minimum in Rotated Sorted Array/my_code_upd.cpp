class Solution {

private:

int Min;

    int BinarySearch(const vector<int>& nums){

        int Left = 0;
        int Right = nums.size();

        while(2 != Right - Left + 1){
            
            const int Mid = Left + (Right - Left) / 2;
            // BordSortedLeft == BSL / BordSortedRight == BSR / Unsorted == U
            int BSL, BSR, BUL, BUR;
            if(nums[Left] <= nums[Mid]){
                BSL = Left;
                BSR = Mid;
                BUL = Mid; // почему не "Mid + 1" ? Ведь получается, что учитваем элемент отсортированной части в не отсортированной. Ответ: может случится 2 == BUR - BUL + 1 и при смещении на "+1" --> BUL == BUR
                BUR = Right;               
            }else{
                BSL = Mid; // почему не "Mid + 1" ? Ведь получается, что учитваем элемент отсортированной части в не отсортированной. Ответ: может случится 2 == BSR - BSL + 1 и при смещении на "+1" --> BSL == BSR
                BSR = Right; 
                BUL = Left; 
                BUR = Mid;                               
            }

            Min = min(Min, nums[BSL]);
            Left = BUL;
            Right = BUR;
            
        }

        return Min;
        
    }

public:
    int findMin(const vector<int>& nums) {
        
        Min = nums.back();

        return BinarySearch(nums);
    }
};
