https://leetcode.com/problems/merge-two-binary-trees/description/

Preorder обход, чтобы сразу обработать узлы, идем в одном направлении, если nodes не nullptr -- суммируем их, в противном случае возвращаем node, которая отлична от **текущего** nullptr
