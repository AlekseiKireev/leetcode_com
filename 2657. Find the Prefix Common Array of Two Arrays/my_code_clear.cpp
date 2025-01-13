/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        const int SIZE = A.size();
        const int CountPermutations = 2;

        vector<int> PrefixCommonArray(SIZE); 
        vector<int> CountValInPrefix(SIZE + 1); 
       
        int SizeCommonPrefix = 0; 

        for(int i = 0; i < SIZE; ++i){

            ++CountValInPrefix[A[i]];
            if(CountValInPrefix[A[i]] == CountPermutations){ 
                ++SizeCommonPrefix;
            }
            
            ++CountValInPrefix[B[i]];
            if(CountValInPrefix[B[i]] == CountPermutations){ 
                ++SizeCommonPrefix;
            }


            PrefixCommonArray[i] = SizeCommonPrefix;

        }

        return PrefixCommonArray;
        
    }
};
