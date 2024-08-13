class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        ranges::sort(citations);

        int CountTotalPaper = citations.size();
        int Ans = 0;
        for(int i = 0; i < CountTotalPaper; ++i){

            if(CountTotalPaper - i <= citations[i]){

                Ans = CountTotalPaper-i;
                break;
            }

        }

        return Ans;
    }
};
