the minimum product of two numbers in an any numbers array https://www.geeksforgeeks.org/minimum-product-pair-an-array-of-positive-integers/

      #include <iostream>
      #include <vector>
      
      int main() {
        int max1 = INT_MIN, max2 = INT_MIN;
        std::vector<int> s{ 5, 4, 3, 6, 8, 2 };
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] > max1) {
            max2 = max1;
            max1 = s[i];
          }
          else if (s[i] > max2) {
            max2 = s[i];
          }
        }
        std::cout << max1 << ' ' << max2;
      }


