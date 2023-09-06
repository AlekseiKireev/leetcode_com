https://leetcode.com/problems/valid-palindrome/

Related: 
- https://leetcode.com/problems/valid-palindrome-ii/
- https://github.com/SkosMartren/leetcode_com/tree/main/680.%20Valid%20Palindrome%20II

https://walkccc.me/LeetCode/problems/0125/

______

[Разбор задачи 125 leetcode.com Valid Palindrome. Решение на C++](https://www.youtube.com/watch?v=JEH5gk_2g34)

Как проверять буквы или цифры.

С++ isalnum  
 - аргумент int.  
- int ожидается >= 0.

char - по спецификации С++ на выбор со знаком или без знака.

signed char или unsigned char.

isalnum(с) - можем получить UB, если символ со знаком - и отрицательный.


Правильно:

isalnum((unsigned char)с)

Сравнить маленькую и большую букву

tolower - приводим к нижнему регистру. 

tolower((unsigned char)с)



__________

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
