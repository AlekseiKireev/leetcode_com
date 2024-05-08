class Solution { 
public:

  static const int EQUAL_COUNT = 3;

  int singleNumber(const vector<int>& nums) {

    const int INT_BIT_SIZE = sizeof(int) * 8;
    size_t countOnes[INT_BIT_SIZE] = {}; // будет содержать либо 0, либо 1, либо число кратное 3, т.е. 3t, либо число вида 3t+1
    
    for (unsigned int x : nums) {

          for (int bit = 0; bit < INT_BIT_SIZE; bit++) { 
          countOnes[bit] += x & 1; // x & 1 используется для получения значения крайнего бита числа x.
          x >>= 1; // x >>= 1 сдвигает число x вправо на один бит, чтобы проверить следующий бит.
          }

    }

    unsigned int ans = 0;
    for (int bit = 0; bit < INT_BIT_SIZE; bit++) {
     ans |= (unsigned int)(countOnes[bit] % EQUAL_COUNT) << bit;
    }

    return ans;

  }
};
/*
Input
nums =
[0,1,0,1,0,1,99]
Stdout
4 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 


Input
nums =
[2,2,3,2]
Stdout
1 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 


Input
nums =
[4,4,3,4]
Stdout
1 1 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 


Input
nums =
[4,4,3,4,6,6,6]
Stdout
1 4 6 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*/
