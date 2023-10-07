https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

related:
- Данная задача следует из https://github.com/SkosMartren/leetcode_com/tree/main/1004.%20Max%20Consecutive%20Ones%20III

https://walkccc.me/LeetCode/problems/1493/

У Федора Меньшикова разбор отсут-т!

Алгоритм: Sliding Window

_____

Основная разница между 1004. Max Consecutive Ones III и 1493. Longest Subarray of 1's After Deleting One Element заключется в том, что в 1004 ***заменяется*** не более CountUpdZero нулей, в то время как в 1493 ***удаляется*** ровно один элемент. Поэтому, если в 1004 ответом является Ans, то в 1493 ответом является Ans - CountUpdZero 
