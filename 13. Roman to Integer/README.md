https://leetcode.com/problems/roman-to-integer/description/

[Разбор задачи 13 leetcode.com Roman to Integer. Решение на C++](https://www.youtube.com/watch?v=ucCArP5ZJtg&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

___________

Example 1

s = "III"  
$I \geqslant I \geqslant I$ --> output: $I + I + I = 1 + 1 + 1 = 3$

Example 2

s = "LVIII"   
$L \geqslant V \geqslant I \geqslant I \geqslant I$ --> output: $L + V + I + I + I = 50 + 5 + 1 + 1 + 1 = 58$

Example 3

s = "MCMXCIV"  
$M \geqslant CM \geqslant XC \geqslant IV$ --> output: $M + (M - C) + (C - X) + (V - I) = M + C + (M - 2C) + X + (C - 2X) + I + (V - 2I) =  M + C + M+ X + C+ I + V - 2(C + X + I)$

__________

Ввиду условия:

I can be placed before V (5) and X (10) to make 4 and 9.  
X can be placed before L (50) and C (100) to make 40 and 90.  
C can be placed before D (500) and M (1000) to make 400 and 900.  

Можно утверждать, что для шаблонного римского числа "... FGHK ..." может быть такая расстановка:  

1. $... F \geqslant G \geqslant H \geqslant K ...$ --> output: $... + F + G + H + K + ...$  
2. $... F \geqslant GH \geqslant K...$ --> output: $... + F  + H - G + K + ... = ... + F + G + H + K - 2(G) ...$  
3. $... F  G \geqslant H  K ...$ --> output: $... ...$
