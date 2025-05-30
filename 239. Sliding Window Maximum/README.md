https://leetcode.com/problems/sliding-window-maximum/description/

https://walkccc.me/LeetCode/problems/239/

https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

У Федора Меньшикова разбор отсут-т!

Удобнее всего представить решение на основе возрастающего nums

    [0,2,4,5,9]
    5

<br>

    [0,2,4,5,9]
    2

При k = nums.size() задача вырождает в поиск максимального элемента в масиве
    
____

Объяснение кода:
* Инициализация:

result: Вектор, в который будут добавляться максимальные значения для каждого положения окна.  
windowIndices: Дек, который будет хранить индексы элементов в текущем окне.


* Основной цикл:

Проходим по всем элементам массива nums с помощью индекса i.

* Обновление дек (очередь):

Внутренний цикл while: удаляем из дека индексы тех элементов, которые меньше текущего элемента nums[i]. Эти элементы не могут быть максимумом в текущем окне, так как текущий элемент больше их и находится в текущем окне.

* Добавление текущего индекса:

Добавляем текущий индекс i в дек.

* Удаление старых индексов:

Если индекс, находящийся в начале дека (самый старый элемент) выходит за границы текущего окна (т.е. i - k), удаляем его из дека.

* Добавление максимального значения в результат:

Когда индекс i становится больше или равен k - 1 (окно полностью сформировано), добавляем значение nums[windowIndices.front()] в вектор result. Это значение является максимальным в текущем окне.

* Итог:

Этот алгоритм использует дек (двустороннюю очередь) для хранения индексов элементов текущего окна и поддержания максимального элемента в начале дека. В результате, максимальный элемент каждого окна добавляется в вектор result, который и возвращается в конце выполнения функции.



___

Задача с собеседования в Яндекс. 
Пусть задан массив из n целых чисел. По этому массиву будут ходить два указателя l и r (0 ≤ l, r < n). Изначально оба они указывают на первый элемент массива (l = r = 0). Оба указателя могут двигаться только вправо, на одну позицию за раз. При этом указатель l никогда не оказывается правее указателя r, и ни один из них не выходит за пределы массива. Вам нужно после каждого перемещения указателя определить максимум всех элементов от указателя l вправо до указателя r (включая позиции, на которые указывают l и r).

Указание. Учетная стоимость обработки каждого запроса на перемещение и подсчет максимума должна оказаться O(1).
Например: 
10  
1 4 2 3 5 8 6 7 9 10  
12  
R R L R R R L L L R L L  
Ответ  
4 4 4 4 5 8 8 8 8 8 8 6 

Решение: 
Существует знаменитый алгоритм, который называется невозрастающая очередь. 
Суть алгоритма такая - мы должны поддерживать очередь dq в которой будет находиться невозрастающие числа на отрезке [l, r]. 

Рассмотрим на примере выше, чтобы лучше понять как работает очередь. 
В первый момент времени l = r = 0 и dq = {1}. 

Передвигаем правый указатель и получаем l = 0, r = 1 должны добавить число 4 в очередь. Удалим с конца все числа которые небольше числа 4 и получаем dq = {4}. 

Передвигаем правый указатель и получаем l = 0, r = 2 так как число a[r] = 2 меньше чем 4 то мы просто добавим это число в очередь и получим dq = {4, 2}. 

Передвигаем левый указатель и получим l = 1, r = 2. Когда сдвигается левый указатель - это означает, что мы должны удалить все числа слева которые < a[l]. В этом случае не удаляем ничего так как 4 > a[l] = 1. 

Передвигаем правый указатель и получим l = 1, r = 3, наша очередь станет равно dq = {4, 3}. 

Передвигаем правый указатель и получим l = 1, r = 4, наша очередь станет равно dq = {5}. 

Передвигаем правый указатель и получим l = 1, r = 5, наша очередь станет равно dq = {8}
И так далее. 

Самое главное поддерживать инвариант - в очереди числа идут по убывания. Все числа в очереди - это подпоследовательность чисел на отрезке [l, r]. 
Ответом после каждого сдвига указателя - это левое число в очереди. 


Время работы O(N)

ChatGPT
Для решения задачи с использованием невозрастающей очереди в C++, следуйте этому алгоритму:

Используйте deque для хранения индексов элементов массива.
Поддерживайте очереди таким образом, чтобы элементы всегда были в невозрастающем порядке по значению.
При перемещении указателя r вправо, добавляйте текущий элемент в очередь, удаляя из очереди все элементы, которые меньше текущего.
При перемещении указателя l вправо, удаляйте элементы из головы очереди, если они выходят за пределы текущего диапазона [l, r].
В любой момент максимальный элемент на отрезке [l, r] находится в голове очереди.
Ниже приведен пример реализации на C++:


        #include <iostream>
        #include <deque>
        #include <vector>
        using namespace std;
        
        void findMaxInRange(vector<int>& arr, vector<char>& moves) {
            int n = arr.size();
            deque<int> dq;
            int l = 0, r = 0;
        
            // Изначально добавляем первый элемент в очередь
            dq.push_back(0);
        
            for (char move : moves) {
                if (move == 'R') {
                    ++r;
                    // Удаляем элементы с конца очереди, которые меньше текущего
                    while (!dq.empty() && arr[dq.back()] <= arr[r]) {
                        dq.pop_back();
                    }
                    dq.push_back(r);
                } else if (move == 'L') {
                    ++l;
                }
        
                // Удаляем элементы с начала очереди, которые выходят за пределы диапазона
                if (!dq.empty() && dq.front() < l) {
                    dq.pop_front();
                }
        
                // Максимум в текущем диапазоне [l, r]
                cout << arr[dq.front()] << " ";
            }
        }
        
        int main() {
            int n = 10;
            vector<int> arr = {1, 4, 2, 3, 5, 8, 6, 7, 9, 10};
            vector<char> moves = {'R', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'L', 'L'};
        
            findMaxInRange(arr, moves);
        
            return 0;
        }

Объяснение
Инициализация:

Создаем deque для хранения индексов элементов массива.
Начинаем с обоими указателями l и r, установленными на первый элемент массива.
Обработка перемещений:

Если движение R (вправо), увеличиваем указатель r и добавляем текущий элемент в deque, удаляя все элементы с конца очереди, которые меньше текущего.
Если движение L (вправо), увеличиваем указатель l.
Удаление элементов, выходящих за пределы диапазона:

Если элемент с начала очереди выходит за пределы диапазона [l, r], удаляем его из очереди.
Вывод максимума:

Максимум в текущем диапазоне [l, r] всегда находится в начале deque.
Этот алгоритм имеет временную сложность O(N), так как каждый элемент добавляется и удаляется из очереди не более одного раза.

---

---

---

---

Да, в этом решении используется **монотонная дека**, которая является вариацией монотонного стека. Рассмотрим подробно, как и где это происходит.

---

### Как работает этот алгоритм?

1. **Цель:** Найти максимальный элемент в каждом подотрезке длины \( k \) в массиве `nums`.
2. **Структура данных:** Используется `deque<int> windowIndices` для хранения индексов элементов массива `nums`. Эта дека поддерживается в **монотонном порядке убывания значений**.

---

### Где и как используется монотонность?

#### 1. Удаление элементов из конца дека:
```cpp
while (!windowIndices.empty() && nums[windowIndices.back()] <= nums[i]) { 
    windowIndices.pop_back();
}
```
- **Зачем это нужно?**
  - Если текущий элемент `nums[i]` больше или равен элементу `nums[windowIndices.back()]` (находящемуся в конце дека), то последний становится неактуальным, так как он никогда не станет максимумом ни для текущего, ни для будущих окон.
- **Монотонность:** После выполнения этого цикла дека `windowIndices` содержит индексы элементов в порядке убывания их значений.

---

#### 2. Добавление нового элемента в деку:
```cpp
windowIndices.push_back(i);
```
- После удаления всех меньших элементов из дека, текущий индекс `i` добавляется в деку.

---

#### 3. Удаление устаревших индексов из начала дека:
```cpp
if (windowIndices.front() < i - k + 1) { 
    windowIndices.pop_front();
}
```
- **Зачем это нужно?**
  - Удаляем индексы, которые выходят за пределы текущего окна длины \( k \). Индексы в начале дека становятся неактуальными, если они меньше \( i - k + 1 \).
- **Поддержание актуальности дека:** Это гарантирует, что первый элемент дека всегда представляет индекс максимального элемента для текущего окна.

---

#### 4. Получение максимума текущего окна:
```cpp
if (i - k + 1 >= 0) { 
    result.push_back(nums[windowIndices.front()]); 
}
```
- **Почему `windowIndices.front()`?**
  - Поскольку дека поддерживается в убывающем порядке значений, первый элемент дека (его индекс) всегда соответствует максимальному элементу текущего окна.

---

### Итог:

- **Монотонный стек:** Здесь `deque` реализует свойства **монотонного стека**, поддерживая порядок убывания значений.
- **Где именно:** В строках, где:
  - Меньшие элементы удаляются из конца дека.
  - Устаревшие индексы удаляются из начала дека.
- **Сложность:**
  - **Время:** \( O(n) \), так как каждый элемент добавляется и удаляется из дека не более одного раза.
  - **Память:** \( O(k) \), так как дека хранит максимум \( k \) индексов одновременно.

Эта реализация эффективно использует свойства монотонной дека для решения задачи о скользящем максимуме.
