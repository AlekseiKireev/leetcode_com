https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ <-- https://leetcode.com/problems/search-in-rotated-sorted-array/

related:
- https://github.com/SkosMartren/leetcode_com/tree/main/33.%20Search%20in%20Rotated%20Sorted%20Array
- https://github.com/SkosMartren/leetcode_com/tree/main/704.%20Binary%20Search

https://walkccc.me/LeetCode/problems/0153/

У Федора Меньшикова разбор отсут-т!

___________________

Утверждение: если поделить nums на две части, т.е. nums == {nums.begin(), nums.begin() + step} UNION {nums.begin() + step + 1, nums.end()} -- то хотя бы одна часть будет отсортирована.

Пример:  
- [7,6,5,4,2,1,0] -- ни одна часть (из двух возможных) не отсортирована по возрастанию: это невозможно ввиду условия задачи: "Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). "
- [4,5,6,7,0,1,2] == {4,5,6,7} UNION {0,1,2} -- обе части отсортированы  
- [4,5,6,7,0,1,2] == {4,5,6,7,0} UNION {1,2} -- правая часть отсортирована
- [4,5,6,7,0,1,2] == {4,5,6} UNION {7,0,1,2} -- левая часть отсортирована

Если переносить крайние элементы из отсортированных частей, от этого свойтсво отсортированности не исчезнет. Утверждение доказано. 

Условие отсортированности: 
- \*nums.begin() < \*(nums.begin() + step)
- \*(nums.begin() + step + 1) < \*(nums.end() - 1)


Алгоритм имеет вид:  
1. Находим середину отрезка [left, right]
2. Находим отсортированный участок (см. утверждение)
3. сравниваем текущей минимум и ***левую границу*** отсортированного участка. Так как иваринат бинарного поиска построен так, что right != left && left < right, то иначально минимум инициализируется nums.back(), чтобы исследовать этот элемент. Пример теста: [2,3,1] -- минимум в nums.back(). 
4. По возможности, лучше отдельно обработать случаи nums.size() = 1 AND nums.size() = 2, так как бинарный поиск работате когда между указателями есть хотя бы один элемент. 
________________

[17,15,13,11] Invalid Testcase Case 1 Edit Not a valid input.
