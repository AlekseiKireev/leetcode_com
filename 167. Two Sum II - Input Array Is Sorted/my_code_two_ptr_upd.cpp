class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int LeftPtr = 0;
        int RightPtr = numbers.size() - 1;

        while(numbers[LeftPtr] != target - numbers[RightPtr]){ // "The tests are generated such that there is exactly one solution. " -- в противнмо случае пришлось бы делать ограничение на указатели

            // так как numbers[LeftPtr] != target - numbers[RightPtr] --> numbers[LeftPtr] < target - numbers[RightPtr] или numbers[LeftPtr] > target - numbers[RightPtr]
            // В первом случае увеличиваем numbers[LeftPtr] + numbers[RightPtr] (сдвигаем левый указатель) -- во втором - уменьшем (сдвигаем правый указатель)
            (numbers[LeftPtr] < target - numbers[RightPtr]) ? ++LeftPtr : --RightPtr;
        }

        return {LeftPtr + 1, RightPtr + 1};

    }
};
