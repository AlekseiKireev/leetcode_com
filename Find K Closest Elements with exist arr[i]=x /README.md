https://t.me/algoses/250
    
    Задача: 
    Дан отсортированный по неубыванию список целых чисел a, индекс элемента index и целое число k. 
    Необходимо вернуть в любом порядке k  чисел из списка, которые являются ближайшими по значению к элементу a[index].  
     
    Ограничения: 
    - Размер списка 1 <= N <= 10^6 ; 
    - Элементы списка: -10^9 <= a[i] <= 10^9 ; 
    - Число 0 < k <= N ; 
    - Индекс элемента 0 <= index < N . 
    - Среди двух одинаково отдалённых элементов выбирается больший 
      
    find_k_closest(a=[2, 3, 5, 7, 11], index=3, k=2) -> [5, 7] 
    find_k_closest(a=[11, 12, 15, 15, 24], index=1, k=3) -> [11, 12, 15] 
    find_k_closest(a=[2, 3, 5, 7, 11], index=2, k=2) -> [5, 7] 
    
    Решение:
    Так как массив отсортирован, в ответ попадут несколько элементов слева от index и сколько-то элементов правее от index. 
    
    В ответ обязательно попадет a[index], так как расстояние ноль. 
    Дальше смотрим на соседей index (справа и слева), кто ближе, того и добавляем в ответ, и сдвигаем указатель. 
    
    Будьте осторожны с выходом за пределы массива.
    
    def find_k_closest(a: list[int], index: int, k: int) -> list: 
        left_ptr = index - 1 
        right_ptr = index + 1 
        k_closest = [a[index]] 
        while len(k_closest) != k: 
            if left_ptr < 0 or ((right_ptr < len(a)) and (abs(a[index] - a[right_ptr]) <= abs(a[index] - a[left_ptr]))): 
                k_closest.append(a[right_ptr]) 
                right_ptr += 1 
            elif left_ptr >= 0: 
                k_closest.append(a[left_ptr]) 
                left_ptr -= 1 
     
        return k_closest 
    
