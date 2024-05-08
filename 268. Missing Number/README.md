https://leetcode.com/problems/missing-number/description/

Примечательно то, что решение с SumNaturalRyad менее практично, нежели через XOR, так как оно может быть подвержено переполнению.

https://walkccc.me/LeetCode/problems/268/

[Разбор задачи 268 leetcode.com Missing Number. Решение на C++](https://www.youtube.com/watch?v=yVkWvWpHXhc&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

_______

в итоге должна получиться формула: n^(0 ^ 1 ^ 2 ^ ... ^ n-1) ^ (nums[0] ^ nums[1] ^ nums[n-1]) = val -- что аналогично https://github.com/SkosMartren/leetcode_com/tree/main/136.%20Single%20Number 
<-- 
https://github.com/SkosMartren/leetcode_com/tree/main/137.%20Single%20Number%20II
