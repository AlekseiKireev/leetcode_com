class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0; i < numbers.size(); ++i){

            const int j = lower_bound(numbers.begin(), numbers.end(), target - numbers[i]) - numbers.begin();

            /* "i != j"  на случай numbers = [0,0,3,4] target = 0*/
            /* "j !=  numbers.size()"  на случай numbers = [1,3,4,4] target = 8*/
            if(j !=  numbers.size()  && i != j && numbers[j] == target - numbers[i]){ 

                return { min(i + 1, j + 1), max(i + 1, j + 1) }; 
                
            }

        }

        return {};
        
    }
};
