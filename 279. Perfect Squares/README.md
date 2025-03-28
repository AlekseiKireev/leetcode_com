my_code.cpp == 279b.cpp <-- my_code_degree_N.cpp 

my_code_math.cpp == [Теорема Лагранжа о сумме четырёх квадратов](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%9B%D0%B0%D0%B3%D1%80%D0%B0%D0%BD%D0%B6%D0%B0_%D0%BE_%D1%81%D1%83%D0%BC%D0%BC%D0%B5_%D1%87%D0%B5%D1%82%D1%8B%D1%80%D1%91%D1%85_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%BE%D0%B2)
+
[Теорема Лежандра о трёх квадратах](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%9B%D0%B5%D0%B6%D0%B0%D0%BD%D0%B4%D1%80%D0%B0_%D0%BE_%D1%82%D1%80%D1%91%D1%85_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%B0%D1%85)
________

https://leetcode.com/problems/perfect-squares/ 

https://walkccc.me/LeetCode/problems/0279/ -- аналог 279b.cpp

[Разбор задачи 279 leetcode.com Perfect Squares. Решение на C++](https://www.youtube.com/watch?v=yUqNob_zPIg)

Аналог: https://contest.yandex.ru/contest/45469/problems/21/ -- my_code_degree_N.cpp обобщенное решение проблемы

```objectives
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	if (N < 8) { cout << N; return 0; }

	vector<int> DP(N+1, 101); // DP[i] == наименьшее число слагаемых в кубическом разложении числа i : i \in |N --> искомое == DP.back()
	DP[0] = 0;

     for (int sum = 1; sum <= N; sum++) {
       for (int first = 1; first * first * first <= sum; first++) { // first * first <= sum <-->  0 <= sum - first * first -- что используется далее в nSq[sum - first * first]
         
         // min -- по условию задачи
         DP[sum] = min(DP[sum],  DP[sum - first * first * first] + 1 );   // "+ 1" обусловлен тем, что из "sum - first * first" можно получить "sum" 
         // добавлением одного perfect square = first * first -- значит количество слагаемых увеличивается на 1
         
       } 
    }


	cout << DP.back();
}
```
_______________________

0. Наивное решение.

Перебираем первое слагаемое - и рекурсивно вызываем перебор
от того, что осталось - выбираем лучший вариант.

13 -> 1+[12]  
13 -> 4+[9]  
13 -> 9+[4]  
13 -> 1б+? -не вариант  

Перебор первого слагаемого О(sqrt(n)) -- ассимптотика такая ввиду того, что перебираем квадраты натуральных чисел от 1 до n 

Общая сложность перебора от количества слагаемых. 

Ответ от 1 до 4 -- [Теорема Лагранжа о сумме четырёх квадратов](https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%9B%D0%B0%D0%B3%D1%80%D0%B0%D0%BD%D0%B6%D0%B0_%D0%BE_%D1%81%D1%83%D0%BC%D0%BC%D0%B5_%D1%87%D0%B5%D1%82%D1%8B%D1%80%D1%91%D1%85_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%BE%D0%B2).

О(sqrt(n))  перебираем первое слагаемое  
О(sqrt(n)) перебираем второе слагаемое  
О(sqrt(n)) перебираем третье слагаемое  
если что-то осталось - за O(1) можно определить, это полный квадрат или нет.

O(n^1.5) по времени  
O(1) по памяти

1. ДП

Решаем исходную задачу для всех чисел от 0 до n. Массив

Перебираем последнее слагаемое, вычитаем его.

Два варианта порядка циклов  
а) внешний - по числу раскладываемому (num), внутренний - по последнему слагаемому. Отметим, что внутренний цикл перебирается на отрезке [1, (integer)sqrt(num)] -- действительно,
положим num = 100, тогда sqrt(num) = 10, тогда условие DP[i] = min(DP[i], DP[i - j*j] + 1); выдаст один ввиду того, что DP[0] = 0. Если, например, num = 101=1^2 + 10^2, то sqrt(num) = 10.0498..., нам необходимо рассмотреть результат 10?, как видно из разложения.

б) можно поменять циклы местами. Решаем задачу, разрешая всё бОльшие слагаемые.

Количество действий в этих варианта одинаковое - доступ к  памяти лучше в варианте б)

0(n^1.5) по времени  
0(n) по памяти

Возможно у ДП константа у времени лучше.

Сначала пишем формулу / подготавливаем аргументы для нее в рамках аргументов цикла, после чего инициализируем контейнер. Частая практика, что DP имеет какое-то значение по умолчанию, поэтому лучше заняться этим в последнюю очередь, видя требуемую логику

2. Секретный способ O(sqrt(N))

Реализация не предоставляется 

возможно, речь о my_code_math.cpp -- решение которое использует "Теорема Лагранжа о сумме четырёх квадратов" + "Теорема Лежандра о трёх квадратах"
_________________________________________

279a.cpp

veleboks, [7/9/2023 12:46 PM]
квадрат, наверное. (грубая оценка)

Erik, [7/9/2023 12:49 PM]
Почему? Там максимум 4 раза в рекурсию войдет и не более чем sqrt(n) будет в цикле

Erik, [7/9/2023 12:50 PM]
А пон, я дурачек

Erik, [7/9/2023 12:50 PM]
Квадрат, да

____

# Доказательство формулы

Формула DP[i] = min(DP[i], DP[i - w*w] + 1) говорит о том, что для получения минимального количества квадратных чисел, которые суммируются до i, необходимо учитывать все возможные квадраты меньшие или равные i.

DP[i] - это минимальное количество квадратных чисел для суммы i.
DP[i - w*w] - это минимальное количество квадратных чисел для суммы i - w*w, где w*w является квадратом числа, меньше или равного i.
Добавляя 1 к DP[i - w*w], мы учитываем добавление еще одного квадрата w*w к сумме i - w*w, чтобы получить i.
Формула минимизирует количество квадратных чисел, которые суммируются до i, проверяя все возможные квадраты w*w и выбирая минимальное значение.
____

# Процесс изменения элементов DP для n = 5

Начальные значения массива DP:

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 5 | 5 | 5 | 5 | 5 |

Теперь будем пошагово обновлять массив DP:

Шаг 1: i = 1 Для i = 1, w принимает значения 1 (так как sqrt(1) = 1):

DP[1] = min(DP[1], DP[1 - 1*1] + 1) = min(5, DP[0] + 1) = min(5, 1) = 1

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 1 | 5 | 5 | 5 | 5 |

Шаг 2: i = 2 Для i = 2, w принимает значения 1:

DP[2] = min(DP[2], DP[2 - 1 \* 1] + 1) = min(5, DP[1] + 1) = min(5, 2) = 2

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 1 | 2 | 5 | 5 | 5 |

Шаг 3: i = 3 Для i = 3, w принимает значения 1:

DP[3] = min(DP[3], DP[3 - 1*1] + 1) = min(5, DP[2] + 1) = min(5, 3) = 3

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 1 | 2 | 3 | 5 | 5 |

Шаг 4: i = 4 Для i = 4, w принимает значения 1 и 2 (так как sqrt(4) = 2):

DP[4] = min(DP[4], DP[4 - 1\*1] + 1) = min(5, DP[3] + 1) = min(5, 4) = 4  
DP[4] = min(DP[4], DP[4 - 2\*2] + 1) = min(4, DP[0] + 1) = min(4, 1) = 1

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 1 | 2 | 3 | 1 | 5 |

Шаг 5: i = 5 Для i = 5, w принимает значения 1 и 2:

DP[5] = min(DP[5], DP[5 - 1\*1] + 1) = min(5, DP[4] + 1) = min(5, 2) = 2  
DP[5] = min(DP[5], DP[5 - 2\*2] + 1) = min(2, DP[1] + 1) = min(2, 2) = 2

| i  | 0 | 1 | 2 | 3 | 4 | 5 |
|----|---|---|---|---|---|---|
| DP | 0 | 1 | 2 | 3 | 1 | 2 |

Таким образом, окончательный результат для n = 5 равен 2.

т.е.  DP[sum] = min(DP[sum],  DP[sum - first \* first] + 1 ); предоставляет оличетсво разложений числа sum, либо оно было оптимально разложенно до этого, тогда min(DP[sum],  DP[sum - first \* first] + 1 ) = DP[sum], либо число sum - first \* first было разлжено в более оптимальное количество слагаемых, тогда  DP[sum - first \* first] + 1 является более оптимальнымх разложением числа
