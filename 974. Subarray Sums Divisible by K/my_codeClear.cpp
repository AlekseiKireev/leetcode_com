class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        long long CurrentModPrefixSum = 0;        
        vector<int> PrefixMod(k);
        ++PrefixMod[CurrentModPrefixSum]; 
      
        int Ans = 0;
        for(int num : nums){
            CurrentModPrefixSum = (CurrentModPrefixSum + num%k + k)%k; 
            Ans += PrefixMod[CurrentModPrefixSum];
            ++PrefixMod[CurrentModPrefixSum];
        }

        return Ans;

    }
};
