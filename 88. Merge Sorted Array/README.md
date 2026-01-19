https://leetcode.com/problems/merge-sorted-array/description/

- https://leetcode.com/problems/merge-sorted-array/solutions/3436053/beats-100-best-c-java-python-and-javascript-solution-two-pointer-stl/

https://walkccc.me/LeetCode/problems/0088/

Аналог: https://leetcode.com/problems/merge-two-sorted-lists/description/

related: https://github.com/SkosMartren/leetcode_com/tree/main/977.%20Squares%20of%20a%20Sorted%20Array -- связь через проход с конца для ответа

У Федора Меньшикова разбор отсут-т!

Алгоритм: 
1. Нужно слить данные из nums2 в nums1 --> внешний цикл по id_nums2
2. Т.к. происходит обращение к элементам nums1, нужна также проверка на id_nums1.
3. Если id_nums1 >= 0 и nums2\[id_nums2] < nums1\[id_nums1] -- сдвигам id_nums1. Иначе (возможность следует из ограничения в цикле) сдвигаем id_nums2

_____

related with https://en.cppreference.com/w/cpp/algorithm :

Set operations (on sorted ranges)  
- https://github.com/SkosMartren/leetcode_com/tree/main/2215.%20Find%20the%20Difference%20of%20Two%20Arrays
- https://github.com/SkosMartren/leetcode_com/tree/main/350.%20Intersection%20of%20Two%20Arrays%20II

В этой задачи нельзя использовать https://en.cppreference.com/w/cpp/algorithm/set_union, так как по условию ответом должно быть мультимножество.
