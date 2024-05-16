https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

https://walkccc.me/LeetCode/problems/124/

У Федора Меньшикова разбор отсут-т!


_____

https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

visualization algorithms: https://youtu.be/6cA_NDtpyz8?t=143

- положим, искомым является MaxPathSum
- очевидно, каждую node надо проверять на возможность быть ответом, например: [-1,-2,-3], [-1,-2,-3,4,-5,-6,-7]. Поэтому при решение будем использовать postorder обход
- Также важным тестом является [1,2,3]
- если ветка текущего поддерева имеет сумму < 0, то данную ветку не рассматрвиаем
<!---
- идея решения заключается в слияние листов в max(root->left->val, root->right->val, 0), перед этим в выполнить MaxPathSum = max(root->left->val, root->right->val)
-->

Решение удобно предсталвять через призму postorder и деревьях вида

         1
        / \
     NULL   NULL

         1
        / \
     NULL   3

       1
      / \
    2     3
