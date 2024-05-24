https://www.lintcode.com/problem/960/description

Использование values.end() для обозначения отсутствия итератора:

store[num] = nullptr был заменен на store[num] = values.end().
Проверка if(store[num] == nullptr) была заменена на if (store[num] == values.end()).
Добавлена проверка на пустой список в firstUnique():

Если список values пуст, выбрасывается исключение runtime_error.
Таким образом, теперь код работает корректно и обрабатывает все случаи корректно.
