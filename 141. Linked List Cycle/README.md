https://leetcode.com/problems/linked-list-cycle

https://walkccc.me/LeetCode/problems/0141/

https://www.techiedelight.com/ru/detect-cycle-linked-list-floyds-cycle-detection-algorithm/

https://visualgo.net/en/cyclefinding

__________

[Разбор задачи 141 leetcode.com Linked List Cycle. Решение на C++](https://www.youtube.com/watch?v=4mxXON0cJtg)

1. Наивное.

Идём по списку, запоминаем указатели на пройденные ноды. 

unordered_set

Каждый следующий указатель - смотрим, не было ли ещё такого. Если был - выдаём true, если новый указатель nullptr - выдаём false.

O(n) по времени ожидаемое O(n) по памяти

2. O(1) по памяти.

Сложность: не знаем размер цикла. Насколько вперёд бежать, чтобы проверить цикл - непонятно.

Два указателя - медленный и быстрый. 3а один ход медленный переходит на следующий узел списка, быстрый - делает это два раза.

По времени O(n) - медленный указатель за n действий проходит участок до цикла + весь цикл. 
В момент входа в цикл медленного указателя быстрый указатель уже в цикле.  
Пока медленный проходит весь цикл - быстрый его успевает догнать. ~Зn действий max. 
Медленный - не более n, быстрый - не более 2n.

По памяти O(1).

__________

[Черепаха и заяц](https://www.techiedelight.com/ru/detect-cycle-linked-list-floyds-cycle-detection-algorithm/)  

https://en.wikipedia.org/wiki/Cycle_detection

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/141_1.png)

Отметим, что  
0 <= i <= List.size() – 1  
2 <= λ <= List.size() 

1.	Положим, k = 1 AND 2 <= λ <= List.size() -1 --> существует i = λ --> x_i = x_{2i} – условие нахождения цикла
2.	Положим, k = 1 AND λ = List.size() можно добавить виртуальные элементы в front листа, ввиду чего попадаем в ситуацию 1.  

Как итог, ввиду x_i = x_{2i} можно утверждать, что если в List нет одинаковых элементов и встртилось истинность улсовия x_i = x_{2i} – цикл существует. 
Чтобы проверить x_i = x_{2i}, нужно два указателя, один их которых ходит с шагом 1, второй с шагом 2.
