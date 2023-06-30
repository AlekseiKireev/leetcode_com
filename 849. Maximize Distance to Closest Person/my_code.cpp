class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int PrefixSize = 0;
        for(int seat : seats){
            if(!seat){++PrefixSize;}
            else{break;}
        }

        int EndingSize = 0;
        int SuffixSize = 0;

        for(int i = PrefixSize + 1;i<seats.size();++i){

            if(!seats[i]){++EndingSize;}
            else{
                SuffixSize = max(SuffixSize, EndingSize);
                EndingSize = 0;
            }

        }

        SuffixSize = ((SuffixSize%2) ? SuffixSize/2 + 1: SuffixSize/2); // расстояние между Алексом и ближайшим к нему человеком, при условии, что Алекс сидит между двумя людьми
        return max({PrefixSize,SuffixSize ,EndingSize});
    }
};
