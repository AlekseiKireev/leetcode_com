#include <iostream>
using namespace std;

void removeSmileysInPlace(string& s) {
    int writeIdx = 0; // Индекс для записи "чистых" символов
    int i = 0; // Текущий индекс чтения

    while (i < s.size()) {
        if (i + 2 < s.size() && s[i] == ':' && s[i + 1] == '-' && (s[i + 2] == '(' || s[i + 2] == ')')) {
            // Найден начало смайлика
            char del = s[i + 2]; // Определяем тип скобки
            i += 3; // Пропускаем начало смайлика
            
            // Пропускаем последующие одинаковые скобки
            while (i < s.size() && s[i] == del) {
                i++;
            }
        } else {
            // Копируем текущий символ в новое место
            s[writeIdx++] = s[i++];
        }
    }
    
    // Уменьшаем строку до обработанного размера
    s.resize(writeIdx);
}

int main() {
    string s = "A:-:-))):(((AD:-((((feargstrhdhdjhrg:-))):-((((22";
    string s2 = s;

    removeSmileysInPlace(s);
    cout << s << endl;

    cout << (removeSmileys(s2) == s) << endl; // Проверяем корректность
    return 0;
}
