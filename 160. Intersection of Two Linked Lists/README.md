https://leetcode.com/problems/intersection-of-two-linked-lists/description/

та же задача в ином формате: https://github.com/SkosMartren/leetcode_com/tree/main/1650.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%20III

    Nice code, Here's the proof for anyone interested,
    let A = a + C
    and B = b + C
    where a, b are the non-intersection start sequences of A, B correspondingly
    and C is the common intersection end sequence of both A and B
    
    We'll use AB, and BA to represent the concatenation of A followed by B and B followed by A correspondingly,
    So,
    AB = a + C + b + C
    BA = b + C + a + C
    But we know that |a + C + b| = |b + C + a|, where | x | represents the length of the sequence x.
    
    Thus, we'll always meet at the start of C, i.e. the intersection node.
    
    Example:
    A: a1 -> a2 -> c1 -> c2 -> c3 -> null
    B: b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> null
    Then,
    AB: a1 -> a2 -> c1 -> c2 -> c3 -> b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> null
    BA: b1 -> b2 -> b3 -> c1 -> c2 -> c3 -> a1 -> a2 -> c1 -> c2 -> c3 -> null
    
    Intersection is at the second occurrence of c1



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
