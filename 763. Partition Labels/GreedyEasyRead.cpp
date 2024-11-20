/*
Time Complexity: O(N)
Space Complexity: O(alphabet)
*/
class Solution {
public:
    vector<int> partitionLabels(string Str) {
        
        int STR_SIZE = Str.size();

        array<int, 128> CharToLastIdx; //CharToLastIdx.fill(0);
        for(int i = 0; i < STR_SIZE; ++i){
            CharToLastIdx[Str[i]] = i;
        }

        int EndCurrentChunk  = 0; 
        int StartCurrentChunk = 0; 
        vector<int> LengthChanck; LengthChanck.reserve(STR_SIZE);

        for(int i = 0; i < STR_SIZE; ++i){

            EndCurrentChunk = max(EndCurrentChunk, CharToLastIdx[Str[i]]);

            if(EndCurrentChunk == i){
                LengthChanck.push_back(EndCurrentChunk -StartCurrentChunk + 1);
                StartCurrentChunk = i + 1;
            }
        }

        return LengthChanck;

    }
};
