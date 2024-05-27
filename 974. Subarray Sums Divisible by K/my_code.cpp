class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        long long CurrentModPrefixSum = 0;        
        vector<int> PrefixMod(k); // PrefixMod[t] --> count prefix with t mod k
        
        // например: [10], k = 10
        ++PrefixMod[CurrentModPrefixSum]; // если остаток равен 0, то данный аффикс подходит, это надо учесть, наеример: [5,5,5], k =5, Expected = 6 = 1+2+3

        int Ans = 0;
        for(int num : nums){
            CurrentModPrefixSum = (CurrentModPrefixSum + num%k + k)%k; // num%k + k необходим для обработки чисел           

            /* порядок двух нижележащих строк именно такой: 
            добавляем к ответу количество аффиксов, которые имеют CurrentModPrefixSum mod k
            затем увелививаем их количество ввиду текущего CurrentModPrefixSum
            */
            Ans += PrefixMod[CurrentModPrefixSum];
            ++PrefixMod[CurrentModPrefixSum];
        }

        return Ans;

    }
};
