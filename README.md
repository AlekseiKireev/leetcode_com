У Федора Меньшикова разбор отсут-т!

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

Ме Бэ, [6/29/2023 3:03 PM]
есть у кого доступ к платной вервсии на литкоед? Хотел попросить задачу в грейдер залить...

Alexey, [6/29/2023 3:15 PM]
https://www.lintcode.com/problem/

Поищи тут, на китайском литкоде есть некоторые платные
