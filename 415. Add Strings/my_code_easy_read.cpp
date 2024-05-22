class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int FirstRightIdx = num1.size() - 1;
        int SecondRightIdx = num2.size() - 1;

        string TotalSum; TotalSum.reserve(max(FirstRightIdx, SecondRightIdx) + 2);
        int carry = 0;

        while(0 <= FirstRightIdx || 0 <= SecondRightIdx || carry != 0){

            int First = (0 <= FirstRightIdx ) ?  num1[FirstRightIdx] - '0' : 0;
            int Second = (0 <= SecondRightIdx ) ?  num2[SecondRightIdx] - '0' : 0;
            
            TotalSum.push_back((carry + First + Second) % 10 + '0');
            carry = (carry + First + Second) / 10;

            --FirstRightIdx;
            --SecondRightIdx;
        }

        ranges::reverse(TotalSum);
        return TotalSum;
    }
};
