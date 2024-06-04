https://leetcode.com/problems/remove-invalid-parentheses/description/

https://walkccc.me/LeetCode/problems/301/

___

* При проходе слева-направа должен выполняться инвариант: closedParen <= openParen
* При проходе справа-налево должен выполняться инвариант: openParen <= closedParen
* Если оба этих условиях выполняется, то openParen = closedParen -- что и характерно для ПСП
