https://leetcode.com/problems/sum-of-left-leaves/description/

https://walkccc.me/LeetCode/problems/0404/

[Разбор задачи 404 leetcode.com Sum of Left Leaves. Решение на C++](https://www.youtube.com/watch?v=Q2TSiZzRJzM)

______

Обходить можно в любом порядке, главное, чтобы выполнялось условие левого листа: 
        
        IsLeftNode 
            && 
        node->left == nullptr 
            && 
        node->right == nullptr

______

Можно сделать аналогичную задачу: Sum of $Right$ Leaves
