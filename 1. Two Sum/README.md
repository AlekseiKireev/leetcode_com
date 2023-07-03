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

NumbToIdx.count(complement) -- проврека, что существует [не ограничивая общности] nums[j] ля nums[i] 

$NumbToIdx[complement] != idx$ нужно не только для того, чтобы избежать  случай  target = 14 = nums[1] + nums[1]
