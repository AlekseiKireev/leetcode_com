class Solution {
public:
    int removeDuplicates(vector<int>& N) {

        int Idx = 0;

        for(int l = 0; l < N.size(); ){

            int cur = N[l];
            int r = l + 1;

            int Count = 1; // 1 ввиду учета cur, так как r указывает на l + 1
            for(;r < N.size() && cur == N[r]; ++r){
                ++Count;
            }

            if(Count >= 2){ // "each unique element appears at most twice"
                N[Idx++] = cur;
                N[Idx++] = cur;
            }else {
                N[Idx++] = cur;
            }
            
            l = r;
            
        }

        return Idx;

    }
};
