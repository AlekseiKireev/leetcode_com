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
