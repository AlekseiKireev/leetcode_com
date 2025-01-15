int Foo(const std::string & Str) {
 
    int count = 0;
    
    std::vector<bool> CharToExist(128);
    
    for(int L = 0, R = 0; R < Str.size(); ++R){
        
        for(; CharToExist[Str[R]] == true; ++L){
            CharToExist[Str[L]] = false;
        }
        
        CharToExist[Str[R]] = true;
        count += (R - L + 1); // Количество всех подстрок строки n - равно биномиальному коэффициенту (2, n + 1). Т.е. 1/2 * (n+1)n.
    }
    
    return count;
}
/*
 корректно вычисляет количество подстрок, заканчивающихся на текущем символе строки R и не содержащих повторяющихся символов.
 Каждый новый символ на позиции R добавляет R−L+1 подстрок к общему количеству.
 abc
 a
 ab
 abc
 b
 bc
 c
 т.е. откусываем первый символ
*/
