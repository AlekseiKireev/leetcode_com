https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/ -- subscribe to premium.

https://walkccc.me/LeetCode/problems/1650/

https://github.com/doocs/leetcode/tree/main/solution/1600-1699/1650.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III

У Федора Меньшикова разбор отсут-т!
_______

Вроде, были иные задачи на LCA, найти и тематически связать!

related:  
- https://github.com/doocs/leetcode/tree/main/solution/1600-1699/1644.Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20II
- https://github.com/SkosMartren/leetcode_com/tree/main/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree
- https://github.com/SkosMartren/leetcode_com/tree/main/160.%20Intersection%20of%20Two%20Linked%20Lists -- можно разобрать эту задачу и придет осознаниние 1650

---

    Хороший код, вот доказательство для всех, кому интересно,
    пусть A = a + C и B = b + C
    , где a, b - это непересекающиеся начальные последовательности A, B соответственно
    , а C - общая конечная последовательность пересечений как A, так и B
    
    Мы будем использовать AB и BA для представления объединения A, за которым следует B, и B, за которым следует A соответственно,
    так что,
    AB = a + C + b + C
    BA = b + C + a + C
    Но мы знаем, что |a + C + b| = |b + C + a|, где | x | представляет длину последовательности x.
    
    Таким образом, мы всегда будем встречаться в начале C, то есть в узле пересечения.
    
    Пример:
    A: a1 -> a2 -> c1 -> c2 -> c3 -> null
    B: b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> null
    Затем,
    AB: a1 -> a2 -> c1 -> c2 -> c3 -> b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> null
    BA: b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> a1 -> a2 -> c1 -> c2 -> c3 -> null
    
    Пересечение происходит при втором появлении c1    
