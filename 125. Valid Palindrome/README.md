https://leetcode.com/problems/valid-palindrome/


А Б, [7/2/2023 2:15 PM]
Изменения лишь в строках: 

```objectives
  while (l < r && !isalnum(s[l])) {++l;}

    while (l < r && !isalnum(s[r])) {--r;}
```
на 
```objectives
    while (l < r && !isalnum(s[l++])) {}

    while (l < r && !isalnum(s[r--])) {}
```

влекут за собой ошибку. Почему?
ГАД, [7/2/2023 2:32 PM]
разница в том, что во втором случае l++ всегда увеличивает  l, только если верно l<r
и тоже самое с r, он всегда уменьшается, если l<r
