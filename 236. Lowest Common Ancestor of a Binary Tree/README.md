https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

слабый аналог: https://contest.yandex.ru/contest/29403/problems/C/

https://walkccc.me/LeetCode/problems/0236/

[Разбор задачи 236 leetcode.com Lowest Common Ancestor of a Binary Tree. Решение на C++](https://www.youtube.com/watch?v=q3z4CkOhMa4&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

______________________

O(n) по времени и O(h) по памяти - на обход дерева  
В обходе собираем статистику:  
- есть ли в поддереве р
- если ли в поддереве q
- какой их lca  

Эту тройку возвращаем из рекурсивного вызова. 
Когда есть такая информация по левому и правому поддереву - объединяем. 
