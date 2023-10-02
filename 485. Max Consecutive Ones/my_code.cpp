class Solution {
public:
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
};
/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int Ans = 0;
        int CurrentSum = 0;
        for(int num : nums){
            if(num == 1){
                ++CurrentSum;
            }else{ // num == 0            
                CurrentSum = 0; // ex: [1,1,0,1,1,1]
            }

            Ans = max(Ans, CurrentSum); // ex: [1,1,1,1,1]
        }

        return Ans; 

    }
};
*/

/*
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int Ans = 0;
        int CurrentSum = 0;
        for(int num : nums){
            if(num == 1){
                ++CurrentSum;
                Ans = max(Ans, CurrentSum); // ex: [1,1,1,1,1]
            }else{ // num == 0
                
                CurrentSum = 0; // ex: [1,1,0,1,1,1]
            }
            
        }

        return Ans; 

    }
};
*/
