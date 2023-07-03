class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // n из услвоия == nums.size(), так как |[0, n]| = n - 0 + 1, но при этом из [0, n] убрали один элемент
        // поэтому |[0, n] \ {val}| = n - 0 + 1 - 1 = n

        // nums.size() + 1 -- длина натурального ряда
        // + 1 в nums.size() + 1 ввиду "only number in the range that is missing from the array."

        // (0 + nums.size()) == (0 + n)-- сумма первого и последнего элемента натурального ряда
        long long SumNaturalRyad = ((0 + nums.size()) * (nums.size() + 1))/ 2;
        
        for(int num : nums){SumNaturalRyad -= num;}

        return SumNaturalRyad;
    }
};
