class Solution { 
public:
     int singleNumber(const vector<int>& nums) {

          int ans = 0; // 0^x = x
          for (int x : nums) { 
               ans ^= x;
          }

          return ans;
     }

};

