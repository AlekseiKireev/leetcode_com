НЕ РАЗОБРАЛ + СМ. https://www.youtube.com/watch?v=26MPOmLZgcc

https://leetcode.com/problems/longest-repeating-character-replacement/description/

https://walkccc.me/LeetCode/problems/0424/

my_code.cpp считать приоритетным кодом!

У Федора Меньшикова разбор отсут-т!

analoge: https://github.com/SkosMartren/leetcode_com/tree/main/340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters

___

related: 
- https://leetcode.com/problems/max-consecutive-ones-iii/description/ -- более слабая версия задачи с бинарной последовательностью

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/leetcode_424_1004_487_485_1493.png)

___

 the length of the longest substring containing the same letter you can get after performing the above operations == <br>
i - j + 1 == <br>
LengthLongestSubstring = <br>
k + MaxCountRepeatSymb : MaxCountRepeatSymb contained in {s[j], ..., s[k]} -- при условии замены, например, такое рассуждение не верно для теста: Input s = "AAAA" k = 2   Output 6 Expected 4

Для того, чтобы поддерживать глобальный максимум MaxCountRepeatSymb необходимо оттображение CharToCountInSW
