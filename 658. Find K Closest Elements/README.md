https://leetcode.com/problems/find-k-closest-elements/

https://walkccc.me/LeetCode/problems/0658/

https://github.com/doocs/leetcode/tree/main/solution/0600-0699/0658.Find%20K%20Closest%20Elements

У Федора Меньшикова разбор отсут-т!

________

<p align="center">My ex -1</p>

    [1,2,3,4,5]
    4
    4
[2,3,4,5]


    [1,2,3,4,5]
    2
    4
[1,2,3,4]
    
<p align="center">My ex 0</p>

    [1,2,3,4,5]
    5
    3
[1,2,3,4,5]

<p align="center">My ex 1</p>

    [1,2,4,5]
    3
    3
[1,2,4]

<p align="center">My ex 2</p>

    [3,11,12,14,15]
    3
    3
[3,11,12]

<p align="center">My ex 2.1</p>

    [4,11,12,14,15]
    3
    3
[4,11,12]

<p align="center">My ex 3</p>

    [-1,0,1,2,4,5]
    3
    33
[2,4,5]

<p align="center">My ex 4</p>

    [0,1,4,5]
    2
    3
[1,4]

<p align="center">My ex 5</p>

    [0,1,4,5]
    2
    4
[4,5]

<p align="center">My ex 6</p>

    [0,2,2,3,4,6,7,8,9,9]
    4
    5


Expected
[3,4,6,7]


Заметим, что искомое является непрерывным подмассивом, остаеться найти 

________

Ввиду услвоия 

    An integer a is closer to x than an integer b if:
    
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b


можно утверждать, что на arr введен линейный порядок: $a \ \preccurlyeq \ b$  если 
- |a - x| < |b - x|
- или |a - x| == |b - x| и a < b

________

# binary search

- int left = 0;
- int right = (int)arr.size() - k;

чтобы 
left < mid = left + (right - left) / 2 < right 
при смещение на "+ k" гарантировано не выходил за границу массива, так как 
k  <  k + left + (right - left) / 2 <  (int)arr.size() 

при анализе будем рассматривать окно длиною k и откидывать левый / правый префиес / постфикс в случае, если противоположная граница более подходящая, элемент расположен ближе к x. 

Дейтсвительно, если, например, arr[mid] расположен ближе к x, чем arr[mid + k], то arr[mid + k + t] дальше от x чем arr[mid], смысла брать его в окно нет.


https://leetcode.com/problems/find-k-closest-elements/solutions/106426/java-c-python-binary-search-o-log-n-k-k/


    below are my explanation.
    
    assume A[mid] ~ A[mid + k] is sliding window

    move window go right == смещение левого указателя до mid+1
    move window go left  == смещение правого указателя до mid
    
    case 1: x - A[mid] < A[mid + k] - x, need to move window go left
    -------x----A[mid]-----------------A[mid + k]----------
    
    case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
    -------A[mid]----x-----------------A[mid + k]----------
    
    case 3: x - A[mid] > A[mid + k] - x, need to move window go right
    -------A[mid]------------------x---A[mid + k]----------
    
    case 4: x - A[mid] > A[mid + k] - x, need to move window go right
    -------A[mid]---------------------A[mid + k]----x------
    
    I think there can be 2 more cases, where A[mid] == A[mid + k].
    
    case 5: x - A[mid] < A[mid + k] - x, need to move window go left
    -------x----A[mid]/A[mid + k]----------
    
    case 6: x - A[mid] > A[mid + k] - x, need to move window go right
    -------A[mid]/A[mid + k]-----x---------
    
    test case [1,1,2,2,2,2,2,3,3], k=3, x=3 is a example of case 6.
    
    Anyway, all 6 cases can be represented by: x - A[mid] > A[mid + k] - x


________

# Два указателя, линейный поиск

Перефраз: по условию требуется вернуть подмассив чисел длиною k, которые наиболее оптимально удовлетворяют условию

    An integer a is closer to x than an integer b if:
    
    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b

Будем удалять наиболее ***неподходящие*** элементы из префикса и постфикса до тех пор, пока не останется подмассив длиню k.  

Ввиду условия сортировки есть инвариант: i < j --> arr[i] <= arr[j].   
При этом, если $|a - x| == |b - x| == 0$ and $a == b$, то неважно что ближе, можно условится что $a$ ближе, а на следующей итерации, если $prev(a) != b$, просто добавим в ответ элемент b.    
