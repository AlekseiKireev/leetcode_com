https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
- Related: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

https://walkccc.me/LeetCode/problems/0105/ == 105b.cpp

____
105a.cpp == поиск кореня в inorder   
105b.cpp == unordered_map

[Разбор задачи 105 leetcode.com Construct Binary Tree from Preorder and Inorder Traversal. C++](https://www.youtube.com/watch?v=JfWvrnP553k)

preorder [3 9 20 15 7]  
inorder [9 3 15 20 7]

Сразу можем создать корень - первый элемент preorder З.

Левое поддерево - левее 3 в inorder, правое поддерево - правее 3.

Можем получить соответствие

preorder root left... right...   
inorder left... root right...
postorder left... right... root
Сложность:

самая сложная операция - найти корень в inorder.

Линейный проход на один поиск, худший случай - когда в left всё оставшееся поддерево - и так рекурсивно. 
О(nodes^2) 

Очевидное решение для O(nodes) - unordered_map из значения в позицию в inorder.

