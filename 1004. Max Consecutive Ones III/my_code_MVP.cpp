class Solution {
public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {       
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            // if(CountUpdZero != 0){ assert(LeftBorderWindow < RightBorderWindow); } // error: nums = [1,1,1,0,0,0,1,1,1,1,0] k = 2
            if(CountUpdZero != 0){ assert(LeftBorderWindow <= RightBorderWindow); } // LeftBorderWindow == RightBorderWindow по меньшей мере в самом начале, когда указывают на первый элемент
            
            // В отрезке [LeftBorderWindow, RightBorderWindow] содержится максимум CountUpdZero нулей
            Ans = max(Ans, RightBorderWindow - LeftBorderWindow  + 1);
        }

        return Ans;
    }
};
