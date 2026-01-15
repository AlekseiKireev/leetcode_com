https://leetcode.com/problems/invert-binary-tree/description/

https://github.com/doocs/leetcode/tree/main/solution/0200-0299/0226.Invert%20Binary%20Tree

----

PostOrder: каждый узел меняется ПОСЛЕ того, как его дети уже инвертированы
```
       4
     /   \
    2     7
   / \   / \
  1   3 6   9


       4
     /   \
    2     7
   / \   / \
  3   1 6   9

       4
     /   \
    2     7
   / \   / \
  3   1 9   6

       4
     /   \
   7      2
  / \    / \  
 9   6  3   1
```

PreOrder: сверху вниз

```

       4
     /   \
    7     2
   / \   / \
  6   9 1   3


       4
     /   \
    7     2
   / \   / \
  9   6 1   3


       4
     /   \
    7     2
   / \   / \
  9   6 3   1


```


InOrder: ошибочный

```
       4
     /   \
    2     7
   / \   / \
  3   1 6   9


       4
     /   \
    7     2
   / \   / \
  6   9 3   1

       4
     /   \
    7     2
   / \   / \
  6   9 1   3   ❌

```
