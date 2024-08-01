class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
    
public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n)  {  
        // If n is a perfect square, return 1.
        if(is_square(n)) {return 1;  }
        

        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); // 5 = 4 + 1, sqrt(5) = 2.23...
        for(int i = 1; i <= sqrt_n; i++){  
            
            if (is_square(n - i*i)) {
                return 2;  
            }
        }  

        /*
        Теорема Лежандра о трёх квадратах утверждает, что натуральное число может быть представлено суммой трёх квадратов целых чисел 
        {\displaystyle n=x^{2}+y^{2}+z^{2}} тогда и только тогда, когда n НЕ ПРЕДСТАВИМО в виде {\displaystyle n=4^{a}(8b+7)}, где a и b целые.
        */
        // https://ru.wikipedia.org/wiki/%D0%A2%D0%B5%D0%BE%D1%80%D0%B5%D0%BC%D0%B0_%D0%9B%D0%B5%D0%B6%D0%B0%D0%BD%D0%B4%D1%80%D0%B0_%D0%BE_%D1%82%D1%80%D1%91%D1%85_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%B0%D1%85
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while (n%4 == 0) /* n%4 == 0  */
        {
            n /= 4;  
        }

        if (n%8== 7) {
            return 4;
        }

        
        return 3;  
    }  
}; 

/*
class Solution {
public:
    int numSquares(int N) {
        
        int SqrtN = sqrt(N);

        if(SqrtN * SqrtN == N){return 1;}

        for(int i = 1; i <= SqrtN; ++i){

            int Buffer = sqrt(N - i*i);
            if(Buffer * Buffer == N- i*i){return 2;}
        }

        while(N%4 == 0){
            N /= 4;
        }

        return (N%8 == 7) ? 4 : 3;
        
    }
};
*/

/* Если не извлекать из Buffer, то может быть ошибка в приведение к типу данных, так как sqrt возвращает число с плавающей точкой
        for(int i = 1; i <= sqrt_n;++i){
            
            int buf = n - i*i;
            if((int)sqrt(buf) * (int)sqrt(buf) == buf){
                return 2;
            }

        }
*/
