|  idx 	|   0   	| 1  	| 2  	| 3      	| 4  	| 5   	|
|:----:	|:-----:	|----	|----	|--------	|----	|-----	|
| nums 	|   15  	| 16 	| 17 	| 18     	| 19 	| end 	|
|      	| ^ \ csa    |    	|    	| ^ vsvs 	|    	|     	|

ааыфа  йй  
мымы
_____________________

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Ме Бэ, [7/4/2023 1:46 AM]
Друзья, а зачем в Possible implementation (https://en.cppreference.com/w/cpp/algorithm/unique) в

unique (1)
```objectives
template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;
 
    ForwardIt result = first;
    while (++first != last)
        if (!(*result == *first) && ++result != first)
            *result = std::move(*first);
 
    return ++result;
}
```

строка: ++result != first во втором условном операторе?

Ме Бэ, [7/4/2023 1:49 AM]
если что — я закоментировал эту строку и сдал сюда: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ — задача была сдана


Андрей Таусинов, [7/4/2023 12:45 PM]
Целиком условие в комментарии стало:
//         if (!(*result == *first) && ++result != first)   ?
Но тогда ведь мы result перестаем сдвигать.
Или только само сравнение?

По идее, это защита от кольцевых контейнеров, чтобы не задублировать в конце первый элемент, больше ничего в голову не приходит

Соответветственно для большинства контейнеров эта строчка роли не играет

Ме Бэ, [7/4/2023 2:38 PM]
"для большинства контейнеров эта строчка роли не играет" — а разве в C++ по умолчанию есть колцевые контейнеры? Так понимаю, эта заглшука на случай пользовательских кольцевых контейнеров?

Андрей Таусинов, [7/4/2023 2:42 PM]
Вроде, нет, но я могу что-то не знать. В теории можно std::list зациклить, но это похоже на путь в никуда) Так что да скорее всего расчет именно на пользовательские
