class Solution {
public:
    string minWindow(string Str, string Angr) {

        const int STR_SIZE = Str.size();
        const int ANGR_SIZE = Angr.size();

        if(STR_SIZE < ANGR_SIZE){
            return "";
        }

        vector<int> CharAngrToCount(128);

        for(char ch : Angr){
            --CharAngrToCount[ch];
        }

        int LeftPtr = 0, RightPtr = 0;
        int CountCharFromAngr = 0;
        int LeftPtrOnMWS = -1, MinLenghtMWS = STR_SIZE + 1;

        for( ; RightPtr < STR_SIZE; ++RightPtr){

            if(++CharAngrToCount[Str[RightPtr]] <= 0){
                ++CountCharFromAngr;
            }

            for(; CountCharFromAngr == ANGR_SIZE; ++LeftPtr){

                if(RightPtr - LeftPtr + 1 < MinLenghtMWS){
                    MinLenghtMWS = RightPtr - LeftPtr + 1;
                    LeftPtrOnMWS = LeftPtr;
                }

                if(--CharAngrToCount[Str[LeftPtr]] < 0){
                    --CountCharFromAngr;
                }

            }
        }


        return (LeftPtrOnMWS == -1) ? "": Str.substr(LeftPtrOnMWS, MinLenghtMWS);
    }
};
