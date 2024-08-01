class Solution {
public:
    int removeDuplicates(vector<int>& N) {
        
        int Idx = 0;

        for(int l = 0; l < N.size(); ){

            int cur = N[l];
            int r = l + 1;

            for(;r < N.size() && cur == N[r]; ++r);

            N[Idx++] = cur;
            l = r;
            
        }

        return Idx;
    }
};
