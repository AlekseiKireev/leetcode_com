https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

https://walkccc.me/LeetCode/problems/0235/

related:  
- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
- https://github.com/SkosMartren/leetcode_com/tree/main/236.%20Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree -- ЭТО РЕШЕНИЕ ПОДХОДИТ!

____________

[Разбор задачи 235 leetcode.com Lowest Common Ancestor of a Binary Search Tree. Решение на C++](https://www.youtube.com/watch?v=SZp0M7DmHFs)

1. Построение путей до вершин.

Получаем путь от корня до каждой вершины.

Находим этих двух путях последнюю одинаковую вершину. 

Время O(depth(р)+depth(q))      
Память O(depth(р)+depth(q))
             
2. Оптимальный алгоритм.
      
Дерево из условия                       
Вершины 0 и 5
                    
б 2 0                   
6 2 4 5
           
Оба пути получены в ходе поиска по двоичному дереву. 
      
Можем не запоминать сам путь, проходить путь одновременно для р и q.
                                   
Если оба р и q в одном поддереве - или  
оба строго больше а1 текущей вершины, или  
оба строго меньше - идём в это поддерево.
         
Иначе ответ - текущая вершина.

