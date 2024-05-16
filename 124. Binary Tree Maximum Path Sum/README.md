https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

https://walkccc.me/LeetCode/problems/124/

У Федора Меньшикова разбор отсут-т!


_____

- положим, искомым является MaxPathSum
- очевидно, каждую node надо проверять на возможность быть ответом, например: [-1,-2,-3], [-1,-2,-3,4,-5,-6,-7]. Поэтому при решение будем использовать postorder обход
- Также важным тестом является [1,2,3]
<!---
- идея решения заключается в слияние листов в max(root->left->val, root->right->val, 0), перед этим в выполнить MaxPathSum = max(root->left->val, root->right->val)
-->
