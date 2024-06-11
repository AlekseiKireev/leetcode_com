class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B, const int CountPermutations = 2) {
        
        const int SIZE = A.size();

        vector<int> PrefixCommonArray(SIZE);
        vector<int> CountValInPrefix(SIZE + 1); 
        int SizeCommonPrefix = 0;

        for(int i = 0; i < SIZE; ++i){

            for(auto& vec : {A, B}){
                ++CountValInPrefix[vec[i]];
                if(CountValInPrefix[vec[i]] == CountPermutations){
                    ++SizeCommonPrefix;
                }

               PrefixCommonArray[i] = SizeCommonPrefix;
            }
            
        }

        return PrefixCommonArray;
    }
};
