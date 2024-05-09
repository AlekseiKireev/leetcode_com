class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int RightPtr = numbers.size() - 1;

        for (int LeftPtr = 0; LeftPtr < numbers.size(); ++LeftPtr) { // сдвигаем левый указатель --> numbers[LeftPtr] + numbers[RightPtr] увеличивается. 

            while (RightPtr >= 0 && numbers[LeftPtr] + numbers[RightPtr] > target) {
                --RightPtr; // сдвигаем правый указатель --> numbers[LeftPtr] + numbers[RightPtr] уменьшается. 
            } // numbers[LeftPtr] + numbers[RightPtr] <= target

            if (numbers[LeftPtr] + numbers[RightPtr] == target) { return { LeftPtr + 1, RightPtr + 1 }; }
        }

        return {};
    }
};
/*
нашли L и R такие, что numbers[L] + numbers[R] < target
может ли быть такое, что мы потеряли решение пока двигали указатель, например, numbers[L + n] + numbers[R + m] : n,m > 0
Нет, так как numbers[L] + numbers[R + i] > target, тогда numbers[L + n] + numbers[R + i] > target и нет смысла бепокоиться, что что-то упустили. 
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int LeftPtr = 0, RightPtr = numbers.size() - 1; LeftPtr < numbers.size() - 1 ; ++LeftPtr){

            assert(RightPtr != LeftPtr); // инвариант алгоритма "два указателя"
            for( ; RightPtr != LeftPtr && target < numbers[LeftPtr] + numbers[RightPtr]; --RightPtr); // target >= numbers[LeftPtr] + numbers[RightPtr]

            if(target == numbers[LeftPtr] + numbers[RightPtr] ){
                return {LeftPtr + 1, RightPtr + 1};
            }
        }

        return {};
    }
};
*/
