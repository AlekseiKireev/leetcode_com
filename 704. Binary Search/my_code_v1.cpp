class Solution {

public:

    int search(vector<int>& nums, int target) {
        
        if(nums.empty() || target < nums.front() || nums.back() < target){return -1;}

        assert(nums.front() <= target && target <= nums.back());
        
        /* // Wrong Answer 31 / 47 testcases   Input nums = [2,5] target = 5 // при таких указателях не верно обрабатываются случаи с двумя элементами. 
        Это можно исправить написав условие: while(0 <= RightBorder - LeftBorder ){ ... LeftBorder = Mid + 1; ... RightBorder = Mid - 1; 
        int LeftBorder = 0;
        int RightBorder = nums.size() - 1;
        */

        // Если исправить на 0 и nums.size() - 1 то будет ошибка на тестах
        // nums = [5] target = 5
        // nums = [0,5] target = 5
        // т.е. такие данные гарантируют, что между числами будет хотя бы одно число, что позволит войти в цикл
        int LeftBorder = - 1;
        int RightBorder = nums.size();

        while(2 != RightBorder - LeftBorder + 1){

            int Mid = LeftBorder + (RightBorder - LeftBorder) / 2;
            if(nums[Mid] == target){return Mid;}
            if(nums[Mid] < target){
               LeftBorder = Mid;
            }else{ // target < nums[Mid] 
               RightBorder = Mid; // если убрать досрочный выход, то правый указатель будет указвать на ответ, т.е. конечный возврат имеет вид: return (nums[R] == target ? R: -1);
            }

        }

        return -1;
    }

};
