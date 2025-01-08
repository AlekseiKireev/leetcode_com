https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

https://walkccc.me/LeetCode/problems/1752/

     1   <   2
    !^!      ^
     4   >   3

    Если все a <= b, то A уже отсортировано.
    Если все a <= b, но только один a > b,
    мы можем повернуть и сделать b первым элементом.
    В противном случае вернем значение false.
