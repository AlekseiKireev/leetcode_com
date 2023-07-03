https://leetcode.com/problems/is-subsequence/description/

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 

Подпоследовательность строки - это новая строка, которая формируется из исходной строки путем удаления некоторых (может не быть ни одного) символов без нарушения относительного положения оставшихся символов.

Ввиду определения подпоследовательности строки решим задачу с помощью двух указателей: 

1. первый указатель -- T_Idx -- движется по всей строке $t$ с шагом 1

2. второй указатель -- S_ Idx -- движется по строке $s$ с шагом 1 только если t[T_ Idx] == s[S_ Idx].
Подобный сдвиг удовлетворяет условию задачи ввиду определения "Подпоследовательность строки" 

