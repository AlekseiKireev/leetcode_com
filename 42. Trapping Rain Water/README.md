https://leetcode.com/problems/trapping-rain-water/

У Федора Меньшикова разбор отсут-т!

Тренировки по алгоритмам 1.0. лекция 2: «Линейный поиск» Задача #7 

можно посмотреть тесты: https://www.geeksforgeeks.org/trapping-rain-water/

_______

* Находим крайний справа глобальный максимум == GlobalMax = max(GlobalMax, height[i]);
* дальше проходимся двумя указателями слева направа и справа налево до глобального максимума НЕ включительно
* при проходе поддерживаем локальный максимум в [0, GlobalMax - 1] и [GlobalMax + 1, height.size()] == LocalMax = max(LocalMax, height[j]);
* получится, что в итоге вода сможет вытекать ТОЛЬКО со стороны локального максимума (LocalMax <= GlobalMax), а собравшиеся вода = LocalMax - height[j]
