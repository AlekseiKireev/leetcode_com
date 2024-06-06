https://leetcode.com/discuss/interview-question/1585947/remove-all-occurrences-of-a-substring-by-pattern  

А надо за один проход удалить, или пока такая конструкция существует в строке, например: 
"A:-:-)))(((A"

Возврат будет "AA"? Ожидается "A:-(((A"   

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
Дается строка надо убрать все смайлики из строки

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
:-))))

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
:-(((

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
:-)

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
Смайлики

Akniyet Sarsenbek, [5/28/2024 9:21 PM]
:) не смайлик

Akniyet Sarsenbek, [5/28/2024 9:24 PM]
Самйликом считается если начинается с :- и N количество скобок ) или (

        #include <iostream>
        using namespace std;
        
        string removeSmileys(string s) {
            
            int i = 0;
            while (i < s.size()) {
                
                if (s[i] == ':' && i + 2 < s.size() && s[i + 1] == '-' && (s[i + 2] == '(' || s[i + 2] == ')')) {
                    // Найден потенциальный смайлик, теперь нужно проверить количество скобок
                    int j = i + 2;
                    //int count = 0;
                    char ChRemove = s[i + 2];
                    
                    while (j < s.size() && s[j] == ChRemove) {
                        //count++;
                        j++;
                    }
                    s.erase(i, j - i);
                    //s.erase(i, count + 2);
                    
                } else {
                    // Продолжаем поиск
                    i++;
                }
            }
            return s;
        }
        
        int main() {
            string s = "A:-:-)))(((A";
            string result = removeSmileys(s);
            cout << result << endl;  // Выведет "A:-(((A"
            return 0;
        }


https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/
