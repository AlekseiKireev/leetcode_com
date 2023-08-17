https://leetcode.com/problems/flatten-nested-list-iterator/

https://walkccc.me/LeetCode/problems/0341/

____

[Разбор задачи 341 leetcode.com Flatten Nested List Iterator. Решение на C++](https://www.youtube.com/watch?v=8T-0gQqQgEA)

[1,2,3],[],4,[[5,6],[7,8]],9

Текущая позиция:  
- ссылка на текущий список  
- позиция в текущем списке  
- та же информация обо всех списках, в которые текущий список вложен.

Позиция: первая не рассмотренная до конца.

O(count) - максимальное время next/hasNext - и оно же суммарное.   
count - количество Nestedlnteger в структуре.

O(depth) - расход по памяти  
depth - глубина вложенности списков.

____

    // Это интерфейс, который позволяет создавать вложенные списки.
    // Вы не должны внедрять его или строить предположения о его реализации
    class NestedInteger {
      public:
        // Возвращает значение true, если этот NestedInteger содержит одно целое число, а не вложенный список.
        bool isInteger() const;
     
        // Возвращает единственное целое число, которое содержит этот NestedInteger, если оно содержит одно целое число
        // Результат не определен, если этот NestedInteger содержит вложенный список
        int getInteger() const;
     
        // Возвращает вложенный список, который содержит этот NestedInteger, если он содержит вложенный список
        // Результат не определен, если этот NestedInteger содержит одно целое число
        const vector<NestedInteger> &getList() const;
    };


 /**
 * Ваш объект NestedIterator будет создан и вызван как таковой:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
