class Solution {
public:
    int longestOnes(vector<int>& nums, int CountUpdZero) {       

        // сертификат
        /*
            -1 необходим для теста: 
            [0,0,0,0]
            0

            output: 0 != R_Idx_Longest_Subarray - L_Idx_Longest_Subarray + 1
        */
        int L_Idx_Longest_Subarray = -1; 
        int R_Idx_Longest_Subarray = -1;        
        
        int Ans = 0;

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size(); ++RightBorderWindow){ // сдвиг правого указателя

            if(nums[RightBorderWindow] == 0){--CountUpdZero;}
            
            /* // equiv:
            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow] == 0){
                    CountUpdZero++;
                    
                }
                LeftBorderWindow++;
            }
            */
            while(CountUpdZero < 0){ // сдвиг левого указателя
                if(nums[LeftBorderWindow++] == 0){++CountUpdZero;}
            }

            cout << LeftBorderWindow << ' ' << RightBorderWindow << '\n';
            // assert(LeftBorderWindow <= RightBorderWindow); // error: 2 / 55 testcases passed, nums = [0,0,1,1,1,0,0] k = 0

            // // В отрезке [LeftBorderWindow, RightBorderWindow] содержится максимум CountUpdZero нулей
            if(Ans < RightBorderWindow - LeftBorderWindow  + 1){

                L_Idx_Longest_Subarray = LeftBorderWindow;
                R_Idx_Longest_Subarray = RightBorderWindow;

                Ans = RightBorderWindow - LeftBorderWindow + 1;
            }
        }
        
        //cout << L_Idx_Longest_Subarray << ' ' << R_Idx_Longest_Subarray;
        if(L_Idx_Longest_Subarray == -1){return 0;}
        else {assert(Ans == R_Idx_Longest_Subarray - L_Idx_Longest_Subarray + 1);}

        return Ans;
    }
};
