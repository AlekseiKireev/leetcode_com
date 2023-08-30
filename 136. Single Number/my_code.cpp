class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

    }
};
/*
https://en.cppreference.com/w/cpp/algorithm/accumulate -->
https://en.cppreference.com/w/cpp/utility/functional -->
https://en.cppreference.com/w/cpp/utility/functional/bit_xor
*/
