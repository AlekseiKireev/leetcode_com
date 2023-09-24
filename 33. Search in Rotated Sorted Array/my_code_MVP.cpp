class Solution {

private:

    int BinarySearch(const vector<int>& nums, const int target){

        int Left = 0;
        int Right = nums.size() - 1;

        while(2 != Right - Left + 1){
            
            const int Mid = Left + (Right - Left) / 2;
            // BordSortedLeft == BSL / BordSortedRight == BSR / Unsorted == U
            int BSL, BSR, BUL, BUR;
            if(nums[Left] <= nums[Mid]){
                BSL = Left;
                BSR = Mid;
                BUL = Mid; // почему не "Mid + 1" ? Ведь получается, что учитваем элемент отсортированной части в не отсортированной. Ответ: может случится 2 == BUR - BUL + 1 и при смещении на "+1" --> BUL == BUR
                BUR = Right;
                cout << "BUL: " << BUL << '\n';
                cout << "Right: " << Right << '\n';
                
            }else{
                BSL = Mid; // почему не "Mid + 1" ? Ведь получается, что учитваем элемент отсортированной части в не отсортированной. Ответ: может случится 2 == BSR - BSL + 1 и при смещении на "+1" --> BSL == BSR
                BSR = Right; 
                BUL = Left; 
                BUR = Mid;                               
            }

            if(nums[BSL] <= target && target < nums[BSR]){
                const auto It_on_target = lower_bound(nums.begin() + BSL, nums.begin() + BSR + 1, target);
                return ((It_on_target != nums.end() && *It_on_target == target) ? It_on_target - nums.begin()  : -1);
            }else{
                Left = BUL;
                Right = BUR;
            }

            if(nums[Left] == target){return Left;}
        }

        return -1;
        
    }

public:

    int search(const vector<int>& nums, const int target) {
        
        if(nums.front() == target){return 0;}
        if(nums.size() == 1){return -1;}
        if(nums.back() == target){return nums.size() - 1;}

        return BinarySearch(nums, target);
    }

};
