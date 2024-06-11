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

___________

Фёдор Меньшиков 

Алексей, разница между string_view и const string& небольшая, если их использовать только при доступе к конкретному элементу, а при вызове функции передавать string, а не const char *.

Алексей, const string & это ссылка (указатель) на исходную строку + запрет операций модификации. string_view это указатель на символы строки + её размер. Отсюда видно, что string_view чуток предпочтительнее, поскольку там доступ более прямой. Там мы сразу имеем доступ к массиву символов, а const string& это ссылка (указатель) на объект строки, в котором лежит указатель на массив символов.

Также string_view не приведет к созданию объекта в динамическаой памяти, в то время как const string & приведет к созданию объекта string в динамическаой памяти
___________

<h1>Setting the size of an array in a private section</h1>

Киреев Алексей MonsieurAKA, [10/4/2023 3:54 PM]
Друзья, почему такой код ошибочный: 

    #include <array>
    
    using namespace std; 
    
    class foo {
    
    private:
        constexpr int NUMBER_SECONDS = 300;
    
    
    private:
        array<int, NUMBER_SECONDS> timestamps;
    };

ввиду положения constexpr int NUMBER_SECONDS = 300;, но если вынести constexpr int NUMBER_SECONDS = 300; в глобальную область видимости, то все работает. Хотелось бы доказ-а с помощью документации, смотрел тут: https://en.cppreference.com/w/cpp/language/constexpr — не нашел инф-и про ограничение области видимости

Alexander "Ternvein" Isaev, [10/4/2023 3:57 PM]
Потому что область видимости не при чём. static бы.

Ilya Zviagin, [10/4/2023 3:59 PM]
Скажи, прежде всего, а какая для тебя принципиальная разница, где будет находиться эта константа, в классе, или вне класса ?

Киреев Алексей MonsieurAKA, [10/4/2023 4:00 PM]
как таковой нет, хотел разобраться в ошибке, которую впервые встретил

Киреев Алексей MonsieurAKA, [10/4/2023 4:00 PM]
а зачем static там?

Андрей Таусинов, [10/4/2023 4:01 PM]
Чтобы не хранить ее в каждом объекте

Alexander "Ternvein" Isaev, [10/4/2023 4:01 PM]
Потому что без static NUMBER_SECONDS — это обычное поле класса.

Киреев Алексей MonsieurAKA, [10/4/2023 4:02 PM]
резонно, прикольно, понял о чем речь, но не знал, что array так на подобное реагирует, а может, не только array...

Alexander, [10/4/2023 4:03 PM]
даже constexpr? странно как-то. обычные const он вроде в полях не хранит.

Ilya Zviagin, [10/4/2023 4:03 PM]
Раз
A constexpr specifier used in a function or static data member (since C++17) declaration implies inline. 

И два
constexpr variable

A constexpr variable must satisfy the following requirements:

        its type must be a LiteralType
        it must be immediately initialized
        the full-expression of its initialization, including all implicit conversions, constructors calls, etc, must be a constant expression 


Тут подходит второе правило, it must be immediately initialized,  если у тебя member-variable, то она НЕ immediately initialized и НЕ inline

Alexander "Ternvein" Isaev, [10/4/2023 4:03 PM]
Хранит.


