https://leetcode.com/problems/valid-palindrome-ii/

Related:
- https://leetcode.com/problems/valid-palindrome/
- https://github.com/SkosMartren/leetcode_com/tree/main/125.%20Valid%20Palindrome

https://walkccc.me/LeetCode/problems/0680/

________

[Разбор задачи 680 leetcode.com Valid Palindrome II. Решение на C++](https://www.youtube.com/watch?v=qmkoYzakVIQ)

0. Перебрать, какую букву выкидывать - для каждого проверить, не палиндром ли. O(n^2) по времени.

1.

ааааbbbbааааccccааааbbbbаааа 

ааааbbbbааааccccааxааbbbbаааа 

ааааbbbbааxааccccааааbbbbаааа 

Идти с двух сторон исходной строки к середине, пропуская пары одинаковых символов. 
Как только нашли пару различных - перебираем два варианта - тестируем на палиндром либо без левой границы, либо без правой.

По времени: O(n), n=s.size, по памяти O(1).
