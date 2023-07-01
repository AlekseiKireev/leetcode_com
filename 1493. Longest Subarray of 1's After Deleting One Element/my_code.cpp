class Solution {
public:
    int longestSubarray(vector<int>& nums, const int CountUpdZero = 1) {
        
        int L_Idx_Longest_Subarray = 0; 
        int R_Idx_Longest_Subarray = 0; 

        int CountUpdZeroInWindow = CountUpdZero;
        int Ans  = 0;  // длина сегмента [L_Idx, R_Idx], в котором вместо удаления 0 заменили его на 1

        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow < nums.size();++RightBorderWindow){

            if(nums[RightBorderWindow] == 0){--CountUpdZeroInWindow;}

            // обновление леой границы окна, так как при CountUpdZeroInWindow < 0 условие задачи не выполняется.
            while(CountUpdZeroInWindow < 0){
                if(nums[LeftBorderWindow++] == 0){++CountUpdZeroInWindow;}
            }

            // обновление ответа и индексов, так как нашли более длинное окно
            if(Ans < RightBorderWindow - LeftBorderWindow + 1){ // RightBorderWindow - LeftBorderWindow + 1 == длина окна, для которого выполнено условие задачи
                
                L_Idx_Longest_Subarray = LeftBorderWindow;
                R_Idx_Longest_Subarray = RightBorderWindow;

                Ans = R_Idx_Longest_Subarray - L_Idx_Longest_Subarray + 1;
            }
        }

        cout << L_Idx_Longest_Subarray << ' ' << R_Idx_Longest_Subarray; // искомое окно, длину которого ищем, находится в диапозоне [L_Idx, R_Idx - CountUpdZero]
        return Ans - CountUpdZero;
    }
};
