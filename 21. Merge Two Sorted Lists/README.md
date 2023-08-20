https://leetcode.com/problems/merge-two-sorted-lists/

- https://leetcode.com/problems/merge-two-sorted-lists/solutions/1826666/c-easy-to-understand-2-approaches-recursive-iterative/

[Разбор задачи 21 leetcode.com Merge Two Sorted Lists. Решение на C++](https://www.youtube.com/watch?v=JHRG307G0UQ)

https://walkccc.me/LeetCode/problems/0021/ == recursive

Аналог: https://leetcode.com/problems/merge-sorted-array/description/


<p align="center"> my_code_1 </p>

Указатели на node может находится в одном из состояний:   
- оба не указывают на nullptr  
  тогда надо сравнить if (list1->val < list2->val) {/*...*/} и записать адрес min{list1->val, list2->val} в ans->next, при этом сдвинуть адрес min{list1->val, list2->val} до "->next"
- хотя бы один указывание на nullptr
  ту node, которая отлична от nullptr, цепляем за ответ и возвращаем искомое
- оба указывают на nullptr  
  возвращаем искомое
  
<p align="center"> my_code_2 </p>

- цепляем за ans адрес min{list1->val, list2->val}, при этом сдвинуть адрес min{list1->val, list2->val} до "->next"
- цепляем за ans адрес min{list1->val, list2->val} до тех пор, пока хотя бы один не начнет указывать на nullptr
- ту node, которая отлична от nullptr, цепляем за ответ и возвращаем искомое

<p align="center"> my_code_rec </p>
