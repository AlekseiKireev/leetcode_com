https://leetcode.com/problems/two-sum/

https://walkccc.me/LeetCode/problems/0001/

related: https://github.com/SkosMartren/leetcode_com/tree/main/167.%20Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted
____________________


Важный тест: [3,4,5,3,8], target = 6

____________________

[Разбор задачи 1 leetcode.com Two Sum. Решение на C++](https://www.youtube.com/watch?v=WEPGndfosls&ab_channel=3.5%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D0%B8%D0%B2%D0%BD%D0%B5%D0%B4%D0%B5%D0%BB%D1%8E)

___

Хотя бы одно решение существует, если выполняется уравнение: $target = nums[i] + nums[j] \ : \ i \ != \ j$

Примечательно то, что в обоих решениях используется NumbToIdx -- неупорядоченное отображение числа num [из nums] в последний индекс, где это число 
встречается в nums.

Например: 

nums = {5,7,8,7}

Тогда в конечном итоге NumbToIdx = {{7,3}, {8,2}, {5,0}}

Положим, target = 14 = nums[1] + nums[3]

Также отметим, что в обоих решениях есть проверка вида: 

```objectoves
        const int complement = target - nums[idx];

        if (NumbToIdx.count(complement) && NumbToIdx[complement] != idx) {
            return { NumbToIdx[complement], idx };
        }
```

Здесь 

NumbToIdx.count(complement) -- проврека, что существует [не ограничивая общности] nums[j] для nums[i] 

$NumbToIdx[complement] != idx$ нужно не только для того, чтобы избежать  случай  target = 14 = nums[1] + nums[1], но и использовать nums[j] такой, что он равен nums[i]




