    #include <iostream>
    using namespace std;
    
    string removeSmileys(string& s) {
        
        int i = 0;
        while (i < s.size()) {
            
            if (s[i] == ':' && i + 2 < s.size() && s[i + 1] == '-' && (s[i + 2] == '(' || s[i + 2] == ')')) {
                // Найден потенциальный смайлик, теперь нужно проверить количество скобок
                int j = i + 2;
                char ChRemove = s[i + 2];
                
                while (j < s.size() && s[j] == ChRemove) {
                    j++;
                }
                s.erase(i, j - i);

                
            } else {
                // Продолжаем поиск
                i++;
            }
        }
        return s;
    }
    
    int main() {
        string s = "A:-:-)))(((A";
        cout << removeSmileys(s) << endl;  // Выведет "A:-(((A"
        return 0;
    }
/*
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
*/
