class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int SumXOR = nums.size();
        for(int i = 0; i < nums.size();++i){SumXOR = SumXOR ^ i ^ nums[i];}

        return SumXOR; // SumXOR == val -- искомое
    }
};
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int SumXOR = 0;
        for(int i = 1; i <= nums.size();++i){SumXOR ^= i ^ nums[i-1];}

        return SumXOR; // SumXOR == val -- искомое
    }
};
*/
/*
ожидается что в конечном итоге SumXOR = n^(0 ^ 1 ^ 2 ^ ... ^ n-1) ^ (nums[0] ^ nums[1] ^ nums[n-1]) = val


Цепочка равевенства обусловлена свойством: 

a ^ 0 = a
b ^ b = 0

как итог: a ^ b ^ b = a


i \in {0, ..., n-1}
nums[i] \in {0, ..., n} \ val 
*/
