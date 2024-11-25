/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int RequiredAffix) {
        
        unordered_map<int, int> PrefixToCount;
        int PrefixSum = 0;
        ++PrefixToCount[PrefixSum];

        int Ans = 0;

        for(int num : nums){

            PrefixSum += num;
            // ++PrefixToCount[PrefixSum]; // error: Input nums = [-1,-1,1] k = 0 Output 4 Expected 1
            Ans += PrefixToCount[PrefixSum - RequiredAffix]; // PS[n] - PS[m] = RequiredAffix == PrefixSum - PS[m] --> сколько раз можем вычесть PS[m], столько и RequiredAffix
            ++PrefixToCount[PrefixSum];
            
        }

        return Ans;
    }
};
