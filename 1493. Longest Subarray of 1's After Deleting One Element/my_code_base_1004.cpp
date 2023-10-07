class Solution {
public:
    int longestSubarray(vector<int>& nums, int CountUpdZero = 1) {

        int Ans = 0; /*содержит наибольшую длину подмассива, в котором содкржатся 1, после того, как в нем обратили не более CountUpdZero нулей*/
        int CountDeleteZero = CountUpdZero; /* 1 отличие от 1004. Max Consecutive Ones III*/
        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            
            if(CountUpdZero != 0){ assert(LeftBorderWindow <= RightBorderWindow); } 
            
            Ans = max(Ans, RightBorderWindow - LeftBorderWindow  + 1);
        }

        return Ans - CountDeleteZero; /* 2 отличие от 1004. Max Consecutive Ones III*/
    }
};
