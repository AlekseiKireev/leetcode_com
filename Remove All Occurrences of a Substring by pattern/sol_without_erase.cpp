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
    
    string Foo(string& s){
        
        string A;
        
        for(int i = 0; i < s.size(); ){
            
            if(i + 2< s.size() && s[i] == ':' && s[i+1] == '-' && (s[i+2] == '(' || s[i+2] == ')')){
                
                i=i+2;
                char del = s[i];
                for(;i < s.size() && del == s[i];++i);
            }else{
                A.push_back(s[i]);
                ++i;
            }
        }
        
        return A;
        
    }
    
    int main() {
        string s = "A:-:-))):(((AD:-((((feargstrhdhdjhrg:-))):-((((22";
        cout << (removeSmileys(s) == Foo(s) )<< endl;  // 1
        return 0;
    }
