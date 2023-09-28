<details>  
<summary> Сканирующая прямая </summary>  
    https://github.com/SkosMartren/leetcode_com/tree/main/1450.%20Number%20of%20Students%20Doing%20Homework%20at%20a%20Given%20Time
    https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals
    https://github.com/SkosMartren/leetcode_com/tree/main/763.%20Partition%20Labels
    https://github.com/SkosMartren/leetcode_com/tree/main/253.%20Meeting%20Rooms%20II
</details>
______

У Федора Меньшикова разбор отсут-т!

Архив видео https://docs.google.com/spreadsheets/d/1w5JqsXFfNTS7NUT7ujKrt8NvhJiw52S6jfvoo2X_fo8/edit?pli=1#gid=0

https://docs.google.com/spreadsheets/d/1vgoyVzOqueURT7jNXuoEec5dQnIdtUCEqVPX1x0Vx6A/edit?pli=1#gid=0

Архив условий и решений: https://github.com/doocs/leetcode/tree/main/solution
_________

Ускорение ввода-вывода

```objectives
const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();
```

https://codeforces.com/blog/entry/10?locale=ru

https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull

https://codeforces.com/blog/entry/18093?locale=ru

https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio

https://codeforces.com/blog/entry/5217?locale=ru

https://wiki.algocode.ru/index.php?title=%D0%A3%D1%81%D0%BA%D0%BE%D1%80%D0%B5%D0%BD%D0%B8%D0%B5_%D0%B2%D0%B2%D0%BE%D0%B4%D0%B0-%D0%B2%D1%8B%D0%B2%D0%BE%D0%B4%D0%B0

Ме Бэ, [7/12/2023 8:11 PM]
@Slamur 

Дядь Слав, а можно вопрос, а то сам ответ не нашел... почему при сдаче алго задач исплользуют связку 

    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  

но не используют cout.tie(nullptr);


И в чем разница между  
    ios_base::sync_with_stdio(false);  
и   
    ios::sync_with_stdio(false);  

в док-и (https://en.cppreference.com/w/cpp/io/ios_base/sync_with_stdio) исполь-я 2 варинат, а в алго-х задачах решатели часто используют 1

Slava Muravjev, [7/12/2023 8:20 PM]
По сути tie задает синхронизацию (типа ты связан с Х)

И тебе важно, чтобы ввод не синхронизировался с потоком вывода

А обратная синхронизация обычно не важна

Деталей не знаю, но что-то вроде этого

Slava Muravjev, [7/12/2023 8:20 PM]
Про второе хз

________

[Leetcode Premium Unlocker](https://chrome.google.com/webstore/detail/leetcode-premium-unlocker/gnpcbhmchfdadabkcmooljbhgdemgiof)

===

https://chrome.google.com/webstore/detail/leetcode-premium-unlocker/gnpcbhmchfdadabkcmooljbhgdemgiof

Как следствие: https://leetcode.com/list/oy4y273c/ 

Ме Бэ, [6/29/2023 3:03 PM]
есть у кого доступ к платной вервсии на литкоед? Хотел попросить задачу в грейдер залить...

Alexey, [6/29/2023 3:15 PM]
https://www.lintcode.com/problem/

Поищи тут, на китайском литкоде есть некоторые платные

____
Фёдор Меньшиков 

Алексей, разница между string_view и const string& небольшая, если их использовать только при доступе к конкретному элементу, а при вызове функции передавать string, а не const char *.

Алексей, const string & это ссылка (указатель) на исходную строку + запрет операций модификации. string_view это указатель на символы строки + её размер. Отсюда видно, что string_view чуток предпочтительнее, поскольку там доступ более прямой. Там мы сразу имеем доступ к массиву символов, а const string& это ссылка (указатель) на объект строки, в котором лежит указатель на массив символов.

Также string_view не приведет к созданию объекта в динамическаой памяти, в то время как const string & приведет к созданию объекта string в динамическаой памяти

___________

![ alt](https://github.com/SkosMartren/useful-materials/blob/main/asymptotics_containers.png)
