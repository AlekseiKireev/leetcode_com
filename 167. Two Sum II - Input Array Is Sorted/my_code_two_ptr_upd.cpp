class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        const int SIZE = numbers.size();
        int LeftPtr = 0;
        int RightPtr = SIZE - 1;

        while(RightPtr != LeftPtr){

            if(numbers[LeftPtr] == target - numbers[RightPtr]){break;}

            numbers[LeftPtr] < target - numbers[RightPtr] ? ++LeftPtr : --RightPtr;
        }

        return {LeftPtr + 1, RightPtr + 1};

    }
};
