/*

По условию задачи необходимо подсчитать КОЛИЧЕСТВО таких суфиксов Suffix[g] чтобы 
prefixSum[h] - prefixSum[f] = k == Suffix[g] : 0 <= f < h <= nums.size()


Рассмотрим формулу: prefixSum[h] - k = prefixSum[f] и омтетим, что: 
	* prefixSum[h] существует по определнию префиксной суммы, т.е. индекс h -- это конец подмассива в nums: prefixSum[h] = sum(nums[i]) : 0 <= i <= h
	* k дано по условию
	* Тогда, ЕСЛИ СУЩЕСТВУЕТ prefixSum[f], то можно ГАРАНТИРОВАТЬ существование Suffix[g] = k
	* Если Suffix[g] будет сущестоввать на момент исследования prefixSum[h], то выражение prefixSum[h] - prefixSum[f] = k будет истино
	* Теперь задача свелась к следующему утвержению: зафиксируем конец префикса h. Если существует префикс prefixSum[f] = prefixSum[h] - k, 
	  такой, что f < h, то к ответ надо инкрементировать
   	* k = Suffix[g] = sum(nums[i]) : f <= i <= h

*/


class Solution {

private:

using PrefixSum = int; // максимальная сумма префиска достигается в крайнем случае: [1000, ...., 1000] : nums.length = 2 * 10^4 --> 1000 * 2 * 10^4 = 2 * 10^7 < 2^31 - 1  < 2^31 ~ 10^9

using Count = int; // из "1 <= nums.length <= 2 * 10^4" --> что int достаточно. крайний случай: [1000, ...., 1000], k = 1000 : nums.length = 2 * 10^4


struct DataPrefix{

Count count = 0;

// Может быть несколько префиксов с нужной суммой, что видно в count, поэтому используется vector
vector<int> RightIdxPrefixSum;

};

unordered_map<PrefixSum, DataPrefix> PrefixToData;

public:
    int subarraySum(const vector<int>& nums, int k) {
        
        int Number = 0;

        int PrefixSum_h = 0;
        ++PrefixToData[PrefixSum_h].count; 
        PrefixToData[PrefixSum_h].RightIdxPrefixSum.push_back(-1);

        vector<pair<int, int>> IdxsSuffix; 

        for(int h = 0; h < nums.size(); ++h){

            PrefixSum_h += nums[h];
            PrefixToData[PrefixSum_h].RightIdxPrefixSum.push_back(h);

            if(PrefixToData.find(PrefixSum_h - k) != PrefixToData.end()){ // роиск prefixSum[f]

                Number += PrefixToData[PrefixSum_h - k].count;

                for(int val : PrefixToData[PrefixSum_h - k].RightIdxPrefixSum){
                    IdxsSuffix.push_back({val + 1, h}); // сдвиг в "val + 1" необходим начала указывания на суффикс
                }

                
            }

            ++PrefixToData[PrefixSum_h].count;
            

        }

        for(auto [l, r] : IdxsSuffix){
            cout << l << ' ' << r << '\n';
        }

        // return IdxsSuffix.size(); // Wrong Answer 65 / 93 testcases passed 
        return Number;

    }
};
