#include <vector> 
#include <cassert> 
#include <climits> 
#include <stdexcept>
#include <iostream>
#include <limits>

using namespace std;

class Solution {


    bool CheckGreaterOverflow(int n_l, int n_r, int target) {

        if (n_r > 0 && n_l > numeric_limits<int>::max() - n_r) { return true; } // произошло "положительное" переполнение, надо уменьшить число n_l + n_r, а именно сдвинуть правый указатель
        
        if (n_r < 0 && n_l < numeric_limits<int>::min() - n_r) { return false; } // произошло "отрицательное" переполнение, надо уведичить число n_l + n_r, а именно сдвинуть левый указатель

        return n_l + n_r > target;
    }


    bool CheckEquivOverflow(int n_l, int n_r, int target) {

        if (n_r > 0 && n_l > numeric_limits<int>::max() - n_r) { return false; } // произошло "положительное" переполнение, ввиду чего не может гарантироваться эквивалентность

        if (n_r < 0 && n_l < numeric_limits<int>::min() - n_r) { return false; } // произошло "отрицательное" переполнение, ввиду чего не может гарантироваться эквивалентность

        return n_l + n_r == target;
    }


public:

    vector<int> twoSum(const vector<int>& numbers, int target) {

        int RightPtr = numbers.size() - 1;

        for (int LeftPtr = 0; LeftPtr < numbers.size(); ++LeftPtr) { // сдвигаем левый указатель --> numbers[LeftPtr] + numbers[RightPtr] увеличивается. 

            while (RightPtr >= 0 && CheckGreaterOverflow(numbers[LeftPtr], numbers[RightPtr], target)) {
                --RightPtr; // сдвигаем правый указатель --> numbers[LeftPtr] + numbers[RightPtr] уменьшается. 
            }

            if (CheckEquivOverflow(numbers[LeftPtr], numbers[RightPtr], target)) { return { LeftPtr + 1, RightPtr + 1 }; }
        }

        return {};
    }
};

int main() {

    cout << Solution().twoSum({ 1,2,INT_MAX }, 3)[0] << ' ' << Solution().twoSum({ 1,2,INT_MAX }, 3)[1] << '\n'; // 1 2
    cout << Solution().twoSum({ INT_MIN, -1,-2 }, -3)[0] << ' ' << Solution().twoSum({ INT_MIN, -1,-2 }, -3)[1] << '\n'; // 2 3

    return 0;
}
