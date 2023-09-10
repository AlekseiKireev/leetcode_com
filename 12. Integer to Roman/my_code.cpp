class Solution {

private:

struct RomanNum{

    int Value;
    string Symbol;
    
};

public:
    string intToRoman(int Num) {
        
        // const array<RomanNum, 13> DescendingRomanNum = { // why error?
        const vector<RomanNum> DescendingRomanNum = {

        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"},  {50, "L"}, {40, "XL"}, 
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}

        }; 

        string ConvertedRomanNum = ""; ConvertedRomanNum.reserve(to_string(Num).size() * 2);
        for(const auto [val, symb] : DescendingRomanNum){

            const int Count = Num / val;
            Num -= (Count * val);
            for(int i = 0; i < Count; ++i){
                //ConvertedRomanNum.push_back(symb); // error! type symb NOT char
                ConvertedRomanNum += (symb);
            }
        }

        assert(Num == 0);
        ConvertedRomanNum.shrink_to_fit();
        return ConvertedRomanNum;
    }
};
