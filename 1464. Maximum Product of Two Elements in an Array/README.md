https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

related: https://github.com/SkosMartren/leetcode_com/tree/main/628.%20Maximum%20Product%20of%20Three%20Numbers

https://walkccc.me/LeetCode/problems/1464/

    
    class Solution {
     public:
      int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
    
        for (const int num : nums)
          if (num > max1)
            max2 = std::exchange(max1, num); // https://en.cppreference.com/w/cpp/utility/exchange
          else if (num > max2)
            max2 = num;
    
        return (max1 - 1) * (max2 - 1);
      }
    };
