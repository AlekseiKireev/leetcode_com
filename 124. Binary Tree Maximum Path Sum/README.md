https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/603423/python-recursion-stack-thinking-process-diagram/ -- разбор

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


<br>

         1
        / \
     NULL   NULL

         1
        / \
     NULL   3

       1
      / \
    2     3


             -3
             / \
           -1   -2  
         
              3
             / \
            1   2  
         
              3
             / \
            1   -2  

<br>

         Начальное значение int Sum = -1001; обусловленно 
         
         The number of nodes in the tree is in the range [1, 3 * 104].
         -1000 <= Node.val <= 1000

         т.е. гарантировано существует хотя бы одна нода, которая гарантировано больше -1001
<br>

         пояснение к

    int L = max(PostOrder(root->left), 0);
    int R = max(PostOrder(root->right), 0);            

             -1
             / \
           -3   -2  

    В этом случае возвращаем -1, делается это посредством строки
    int RootSum = root->val + L + R;

<br>

         Sum = max(Sum, RootSum); -- обновление ответа

<br>

         Демонстрация к return root->val + max(L, R);

                  1000
                  /
               -1
               /
             1000

