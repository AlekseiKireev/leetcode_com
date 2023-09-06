https://leetcode.com/problems/validate-binary-search-tree/

https://walkccc.me/LeetCode/problems/0098/

[Разбор задачи 98 leetcode.com Validate Binary Search Tree. Решение на C++](https://www.youtube.com/watch?v=Ik2KuUxhuQs&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/BST_1.png)

<img src="https://github.com/SkosMartren/useful-materials/blob/main/BST_1.png" width="1500" height="500"/>


у этой задачи есть ещё одно решение - обходим дерево inorder (можно рекурсивно, можно нерекурсивно) и проверяем, что ключи на пути обхода строго возрастают.

Также аналогичный подход используется в задаче https://leetcode.com/problems/range-sum-of-bst/description/

___________

Предложенное решение в my_code.cpp имеет место быть ввиду того, что ключи имеют тип int. В случае типа ключей long long такое решение было бы ошибочно. 
