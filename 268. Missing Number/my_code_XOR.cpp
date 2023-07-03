class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int SumXOR = nums.size();
        for(int i = 0; i < nums.size();++i){SumXOR = SumXOR ^ i ^ nums[i];}

        return SumXOR; // SumXOR == val -- искомое
    }
};
/*
ожидается что в конечном итоге SumXOR = (0 ^ 1 ^ 2 ^ ... ^ n) ^ (nums[0] ^ nums[1] ^ nums[n-1]) = val


Цепочка равевенства обусловлена свойством: 

a ^ 0 = a
b ^ b = 0

как итог: a ^ b ^ b = a


i \in {0, ..., n-1}
nums[i] \in {0, ..., n} \ val 
*/
