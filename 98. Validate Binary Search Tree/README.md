https://leetcode.com/problems/validate-binary-search-tree/

https://walkccc.me/LeetCode/problems/0098/

________

[Разбор задачи 98 leetcode.com Validate Binary Search Tree. Решение на C++](https://www.youtube.com/watch?v=Ik2KuUxhuQs&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

Передаём в узел для проверки диапазон, в котором должны быть ключи

[INT_MIN, INT_МАХ] - корень

root->val - значение в корне

В левом поддереве [INT_MIN, root->val-1]  
В правом поддереве [root->val+1, INT_МАХ]

val-1 и val+1 могут не существовать.

val == INT_MIN, то не существует val - 1  
val == INT_МАХ, то не существует val + 1

а)  
В случае val == INT_MIN можно проверить, что left == nullptr  
в случае val == INT_МАХ можно проверить, что right == nullptr  
\- не придётся делать рекурсивный вызов

б)  
передавать границы не включительно

(INT_MIN-1, INT_МАХ+1)

(INT_MIN-1, root->val)

(root->val, INT_МАХ+1)

Для значений INT_MIN-1 и INT_МАХ+1 придётся использовать бОльший тип -long long например.  
Могут быть платформы, где int == long long - проблема найти бОльший тип.

Можно отметить, что этой границы "нет".

Передавать int* - если nullptr - границы нет, если не nullptr - указывает на границу.

Можно логическое значение "есть граница".

________

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/BST_1.png)

<img src="https://github.com/SkosMartren/useful-materials/blob/main/BST_1.png" width="1500" height="500"/>


у этой задачи есть ещё одно решение - обходим дерево inorder (можно рекурсивно, можно нерекурсивно) и проверяем, что ключи на пути обхода строго возрастают.

Также аналогичный подход используется в задаче https://leetcode.com/problems/range-sum-of-bst/description/

___________

Предложенное решение в my_code.cpp имеет место быть ввиду того, что ключи имеют тип int. В случае типа ключей long long такое решение было бы ошибочно. 
