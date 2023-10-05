class Solution {
public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {       
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            // В отрезке [LeftBorderWindow, RightBorderWindow] содержится максимум CountUpdZero нулей
            Ans = max(Ans, RightBorderWindow - LeftBorderWindow  + 1);
        }

        return Ans;
    }
};
