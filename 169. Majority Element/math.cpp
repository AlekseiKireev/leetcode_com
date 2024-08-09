class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int Count = 0;
        int CurNum;

        for(int num : nums){

            if(Count == 0){
                CurNum = num;                
            }

            Count += ((CurNum == num) ? +1: -1);

        }

        return CurNum;
    }
};
