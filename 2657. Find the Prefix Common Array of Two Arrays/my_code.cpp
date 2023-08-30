class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        const int SIZE = A.size();
        const int CountPermutations = 2;

        vector<int> PrefixCommonArray(SIZE);
        vector<int> CountValInPrefix(SIZE + 1);
       
        int SizeCommonPrefix = 0; // Количество одинаковых элементов в префиксах массивов A и B длины i + 1 

        for(int i = 0; i < SIZE; ++i){

            ++CountValInPrefix[A[i]];
            if(CountValInPrefix[A[i]] == CountPermutations){ // В префиксах массивов A и B длины i + 1 элемент A[i] встречался CountPermutations раз -- то есть в обоих массивах
                ++SizeCommonPrefix;
            }
            
            ++CountValInPrefix[B[i]];
            if(CountValInPrefix[B[i]] == CountPermutations){ // В префиксах массивов A и B длины i + 1 элемент B[i] встречался CountPermutations раз -- то есть в обоих массивах
                ++SizeCommonPrefix;
            }


            PrefixCommonArray[i] = SizeCommonPrefix;

        }

        return PrefixCommonArray;
        
    }
};

/*
A = [1,3,2,4,5,6], B = [5,6,3,1,2,4]
Output
[0,0,1,2,4,6]
Expected
[0,0,1,2,4,6]

A = [1,2], B = [1,2]
Output
[1,2]
Expected
[1,2]
*/
