class Solution {
public:
    string intToRoman(int num) {
        
        string ConvertedRomanNum(num / 1000, 'M');
        num %= 1000;

        
        vector<string> Hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC" ,"CM"};
        ConvertedRomanNum += Hundreds[num / 100];
        num %= 100;

        vector<string> Dozens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        ConvertedRomanNum += Dozens[num / 10];
        num %= 10;

        vector<string> Units = {"","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        ConvertedRomanNum += Units[num];

        return ConvertedRomanNum;
    }
};
