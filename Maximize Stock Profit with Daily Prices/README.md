https://t.me/algoses/24

Задача с собеседования в Яндекс 
Дан массив 'a' длины N. Массив описывает цену единицы товара на протяжение N дней. 
Каждый день вы выпускаете одну единицу товара и отправление в склад. 
В i-тый день вы можете продать определенное количество товаров из склада по стоимости ai. 
Ваша задача продать все товары таким образом чтобы получить максимальную прибыль. 
Например вам дали массив 1, 3, 1, 2 ответ 10. 
Так как первый и второй товар продадите по стоимости 3, а третий и четвертый по стоимости 2. 

Решение:
Так как в i тый день вы производите новый товар, то продать его можете в день j, где i <= j. 
Очевидно вы должны продать товар i в день j для которого i <= j и a[j] -> max. 

Давайте пройдемся справа налево по массиву поддерживаю максимальное число из массива 'a' которое вы встретили. 
Пусть это число равно mx. Тогда из рассуждений выше, вы должны просо добавить в ответ mx. 

Время работы O(N)
