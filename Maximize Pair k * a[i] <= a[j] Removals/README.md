https://t.me/algoses/54

    Задача с Яндекса 
    Дается отсортированный массив a из натуральных чисел, а также дается число k. 
    За одну операцию вы можете выбрать два индекса (i, j) такие, что k * a[i] <= a[j] и зачеркнуть эти числа. 
    Найдите максимальное количество чисел, которые можно зачеркнуть. 
    
    Решение: 
    Обратите внимание, что массив отсортирован. Также заметим, что мы можем зачеркнуть не более len(a) / 2 пар чисел.
    Эти два факта будем использовать в решение. 
    Очевидно, если вы хотите зачеркнуть cnt пар индексов, мы должны взять cnt минимальных чисел 
    и cnt максимальных чисел (то есть cnt первых индексов и столько же последних индексов). 
    Мы понимаем, что cnt <= len(a) / 2. 
    Давайте поставим указатель i = 0 и поставим указатель j = len(a) / 2. 
    Если k * a[i] <= a[j] мы сдвинем указатели i, j на один, иначе нам выгодно сдвинуть указатель j, 
    так как a[j] станет больше, а a[i] останется минимально возможный. 
    
    Важно понять, что от того, что мы поставим j = len(a) / 2, а не меньше, ничего плохого не случится. 
    Время работы O(N)
