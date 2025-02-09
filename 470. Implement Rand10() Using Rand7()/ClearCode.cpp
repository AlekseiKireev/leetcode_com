/*
Time:O(1) 
Space:O(1) 
P(успех)=40​/49=p, E[X]=1/p​=49/40​≈1.225
E[кол-во вызовов rand7()]=2×E[X]=2× 49/40 ​ =  98/40≈2.45
*/
class Solution {
 public:
  int rand10() {
    int num = 41;

    while (num > 40){
      num = (rand7() - 1) * 7 + rand7();
    }

    return num % 10 + 1;
  }
};
