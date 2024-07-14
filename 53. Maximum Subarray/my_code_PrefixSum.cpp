// https://e-maxx.ru/algo/maximum_average_segment --> Алгоритм 1

class Solution {

public:

    int maxSubArray(vector<int>& nums) {
        
        /* Отметим, что изначально PrefixSum = MinPrefixSum = 0, а не  nums.front() -- 
        что согласуется с определением префиксных сумм: фронтовое значение массива префиксных сумм равно 0.        
        Это можно увидеть на примере: Input nums = [5,4,7,8] Expected 24
        */
        int PrefixSum = 0; // "int" <-- 10^5 * 10^4 <-- 1 <= nums.length <= 10^5 AND -10^4 <= nums[i] <= 10^4
        int MinPrefixSum = 0; // берем минимальный префикс из отрезка [0, i - 1]

        // "nums.front()" существует ввиду "1 <= nums.length <= 10^5"
        // "MaxAffixSum = 0" будет ошибочным на примере: Wrong Answer 195 / 210 testcases  Input nums = [-1] Output 0 Expected -1
        int MaxAffixSum = nums.front(); // ограничения на MaxAffixSum следуют из ограни-й PrefixSum

        for(int i = 0; i < nums.size(); ++i){ // для каждого префикса диапозона [0, ..., i] находим оптимальный аффикс через вычитаение наименьшего префикса

            // PrefixSum == sum{nums[i]} : 0 <= i <= i
            PrefixSum += nums[i];

            /*  PrefixSum - MinPrefixSum == MaxSuffixSum на [RightIdxMinPrefixSum + 1, i] -- ввиду того, что минимизируем вычитаемое для каждого 
               возможного значения PrefixSum */
            MaxAffixSum = max(MaxAffixSum, PrefixSum - MinPrefixSum); // в данной строке в MinPrefixSum записано значения из диапозона [0, i - 1]

            // MinPrefixSum == sum{nums[i]} : 0 <= i <= RightIdxMinPrefixSum 
            MinPrefixSum = min(MinPrefixSum, PrefixSum); // минимум либо был достигнут ранее -- MinPrefixSum, либо получен при последнем подсчете -- PrefixSum
        }

        return MaxAffixSum; 

    }
};
