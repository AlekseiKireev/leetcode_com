https://t.me/algoses_chat/1465

Задача с собеседования в Яндекс

    Даны два массива A и B. Нужно найти минимум abs(A[i] - B[j])
    
    Пример:
    A = {0}, B = {1}
    Ответ: 1
    
    A = {10, 0, 2}, B = {5, 100, 12}
    Ответ: 2
    Нужно решение без дополнительной памяти.
    
    Решение:
    Отсортируем массивы, далее поставим указатель i на начало A, j на начало B.
    Для текущего i будем двигать j вправо до тех пор, пока значение abs(A[i] - B[j]) будет уменьшаться.
    Иначе сдвинем i вправо и повторим алгоритм.
    
    Можно привести решение с lower-upper_bound, но это зачтут как минус. На собесе хотят увидеть параллельный проход
    
    Также заметим, что если A = {INT_MAX}, B = {-1}, то ответ не поместится в int.
    
    Решение из-за сортировки получается O(nlogn)
    Если в условии массивы изначально отсортированы, то O(n)
