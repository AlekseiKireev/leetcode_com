https://leetcode.com/problems/climbing-stairs/description/

related: https://github.com/SkosMartren/leetcode_com/tree/main/509.%20Fibonacci%20Number

достигнуть i-й ступеньки мы можем сделав шаг со ступеньки i - 1 и со ступеньки i - 2. Поэтому для нахождения всех вариантов пути достаточно сложить варианты путей для достижения двух предыдущих ступенек.
Можно обобщить на k ступенек. Для двух учитываем:

  dp[1] = 1;  
  dp[2] = 2;
