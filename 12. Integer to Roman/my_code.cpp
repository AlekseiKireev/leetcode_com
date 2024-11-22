/*
Time complexity: O(1)
Space complexity: O(1)
*/
class Solution {

private:

struct RomanNum{

    int Value;
    string Symbol;
    
};

public:
    string intToRoman(int Num) {
        
        /* // good!
        const array<RomanNum, 13> DescendingRomanNum = { 
        //const vector<RomanNum> DescendingRomanNum = {
        */
        const array<RomanNum, 13> DescendingRomanNum  { 
        //const vector<RomanNum> DescendingRomanNum  {

        {
            {1000, "M"}, {900, "CM"}, 
            {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"},  
            {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, 
            {5, "V"}, {4, "IV"}, {1, "I"}
        }

        }; 

        string ConvertedRomanNum = ""; ConvertedRomanNum.reserve(to_string(Num).size() * 2);
        for(const auto& [val, symb] : DescendingRomanNum){

            const int Count = Num / val;
            Num -= (Count * val);
            for(int i = 0; i < Count; ++i){
                //ConvertedRomanNum.push_back(symb); // error! type symb NOT char
                ConvertedRomanNum += (symb);
            }
        }

        assert(Num == 0);
        ConvertedRomanNum.shrink_to_fit();
        return ConvertedRomanNum;
    }
};
/*
А Б, [9/10/2023 7:12 PM]
окей, спасибо, сдал вот так: 

        const array<RomanNum, 13> DescendingRomanNum = { 
        //const vector<RomanNum> DescendingRomanNum = {

        {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"},  {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        }

        }; 

Вопрос: какого чуда такая конструкция имеет место быть и почему ты нашел это очевидным? Можно линк на документацию? Проверил: такая конструкция и для vector работает. Зачем она для него работает?)

Андрей Варёнов, [9/10/2023 7:23 PM]
Ну смотри
У std::vector есть конструктор от initializer_list
У std::array нет такого
И собственно почему работает если взять в скобки - потому что у array единственное поле это массив и ты его инициализируешь

Алексей (lewa_j) Иванчуков, [9/10/2023 7:27 PM]
= лишнее

Anton Semenov, [9/10/2023 7:28 PM]
какая чудо-конструкция? std::initializer_list<T>, что ли?  Ну да, у многих контейнеров определен конструктор от этой штуки для удобства.

А вот для std::array все даже проще, у него внутри единственное поле - массив, он инициализируется по правилам обычной структуры

А Б, [9/10/2023 7:32 PM]
а в чем разница с равно и без?

Алексей (lewa_j) Иванчуков, [9/10/2023 7:33 PM]
одно инициализация а другое присваивание




Ме Бэ, [9/5/2023 6:12 PM]
А такие конструкции: 
for (const char ch : {'a', 'b', 'c', 'd', 'e'}) {

любой компилятор принимает? Надо ли делать приведение типа у {'a', 'b', 'c', 'd', 'e'}? И почему надо / не надо?

Georgy Firsov, [9/6/2023 2:42 PM]
С условием поддержки С++11 должен любой
Вот то, что в скобочках -- initializer_list, он имеет begin и end, так что всё ок
*/
