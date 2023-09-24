https://leetcode.com/problems/search-in-rotated-sorted-array/
- https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/3879263/100-binary-search-easy-video-o-log-n-optimal-solution/?envType=list&envId=oy4y273c

related:  
- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
- https://github.com/SkosMartren/leetcode_com/tree/main/704.%20Binary%20Search

https://walkccc.me/LeetCode/problems/0033/

___________________

[Разбор задачи 33 leetcode.com Search in Rotated Sorted Array. Решение на C++](https://www.youtube.com/watch?v=Xh4RMdN2eec)

Аналог двоичного поиска.
Если повторы возможны:

[2,2,2,...,2,2,2]


[2,2,2,2,2,2,2]

[2,2,2,3,2,2,2]

[2,2,2,0,2,2,2]

[ 2, 3, 3, 3, 4, 4, 5, 0,1 ]
Возможно достаточно неравества первого и последнего элемента.

Пример: 

[4,5,6,7,0,1,2] target = 0.

Берём значение в середине. [4...7...2]  
4..7 - в порядке возрастания, 0 не содержит  
7..2 - содержит границу - может содержать любые элементы.  

    Комментарий с youtube для 33a.cpp
    15:00
                    if (target < a[left] || a[right] < target) {
                        return -1;
                    }
    
    можно, пожвлуйста, прояснить оператор.
    Ведь может быть такой сдвиг: 
    
    [4,5,6,7,0,1,2]
    пусть  a[left] = 4, a[right] =7, target = 1
    У нас сработает  target < a[left]  <--> 1 < 4, мы вернем -1, хотя вроде как ожидалось 5. Что не учтено?
    
    Инвариант цикла - left и right с разных сторон от излома.
___________________

Утверждение: если поделить nums на две части, т.е. nums == {nums.begin(), nums.begin() + step} UNION {nums.begin() + step + 1, nums.end()} -- то хотя бы одна часть будет отсортирована.

Пример:  
- [4,5,6,7,0,1,2] == {4,5,6,7} UNION {0,1,2} -- обе части отсортированы  
- [4,5,6,7,0,1,2] == {4,5,6,7,0} UNION {1,2} -- правая часть отсортирована
- [4,5,6,7,0,1,2] == {4,5,6} UNION {7,0,1,2} -- левая часть отсортирована

Условие отсортированности: 
- \*nums.begin() < \*(nums.begin() + step)
- \*(nums.begin() + step + 1) < \*(nums.end() - 1)

Если target в границах отсортированного участка -- ищем его через lower_bound -- иначе сдвигаем указатели на границы не отсортированного участка. 

Алгоритм имеет вид: 
1. Находим середину отрезка [left, right]
2. Находим отсортированный учачсток (см. утверждение)
3. После его анализа сдвигаем границы:
- если target находится в границах [nums[left], nums[right]] исследуем этот участок через lower_bound и выходим из функции
- иначе придется left / right сдвигать на границы неотсортированного участка и повторить алгоритм сначала
