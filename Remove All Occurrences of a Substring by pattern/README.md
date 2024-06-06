https://leetcode.com/discuss/interview-question/1585947/remove-all-occurrences-of-a-substring-by-pattern  

А надо за один проход удалить, или пока такая конструкция существует в строке, например: 
"A:-:-)))(((A"

Возврат будет "AA"? Ожидается "A:-(((A"   


Дается строка надо убрать все смайлики из строки. Самйликом считается если начинается с :- и N количество скобок ) или (

Смайлик

        :-))))
        
        :-(((
        
        :-)


не смайлик

        :) 


related: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
