class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int RightPtr = numbers.size() - 1;

        for (int LeftPtr = 0; LeftPtr < numbers.size(); ++LeftPtr) { // сдвигаем левый указатель --> numbers[LeftPtr] + numbers[RightPtr] увеличивается. 

            while (RightPtr >= 0 && numbers[LeftPtr] + numbers[RightPtr] > target) {
                --RightPtr; // сдвигаем правый указатель --> numbers[LeftPtr] + numbers[RightPtr] уменьшается. 
            }

            if (numbers[LeftPtr] + numbers[RightPtr] == target) { return { LeftPtr + 1, RightPtr + 1 }; }
        }

        return {};
    }
};
