class Solution {
public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {

        int L_Idx_Longest_Subarray = 0; 
        int R_Idx_Longest_Subarray = 0; 

        int CountUpdZeroInWindow = CountUpdZero;
        int Ans = 0;
        
        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}

            while(CountUpdZero < 0){
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            if(Ans < RightBorderWindow - LeftBorderWindow  + 1){

                L_Idx_Longest_Subarray = LeftBorderWindow;
                R_Idx_Longest_Subarray = RightBorderWindow;

                Ans = RightBorderWindow - LeftBorderWindow + 1;
            }
        }

        cout << L_Idx_Longest_Subarray << ' ' << R_Idx_Longest_Subarray;
        return Ans;
    }
};
