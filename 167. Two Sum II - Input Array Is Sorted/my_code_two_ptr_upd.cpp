class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int LeftPtr = 0;
        int RightPtr = numbers.size() - 1;

        while(numbers[LeftPtr] != target - numbers[RightPtr]){ // "The tests are generated such that there is exactly one solution. " -- в противнмо случае пришлось бы делать ограничение на указатели

            (numbers[LeftPtr] < target - numbers[RightPtr]) ? ++LeftPtr : --RightPtr;
        }

        return {LeftPtr + 1, RightPtr + 1};

    }
};
