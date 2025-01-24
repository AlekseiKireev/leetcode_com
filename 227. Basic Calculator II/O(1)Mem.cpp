class Solution {
public:
    int calculate(string s) {

        int length = s.size();
        if (length == 0) { return 0; }

        int RightOperand = 0, LeftOperand = 0, result = 0;
        char sign = '+';

        for (int i = 0; i < length; i++) {

            char currentChar = s[i];

            if (iswspace(currentChar) && i != length - 1) {
                continue;
            }

            if (isdigit(currentChar)) { // формирование текущего числа
                RightOperand = (RightOperand * 10) + (currentChar - '0'); // поразрядное смещение
            }

            if (!isdigit(currentChar) || i == length - 1) { // На последнем символе мы обязаны обработать последнее число. 
                if (sign == '+' || sign == '-') {
                    result += LeftOperand;
                    LeftOperand = ((sign == '+') ? RightOperand : -RightOperand);
                } else if (sign == '*') { // Мы не добавляем LeftOperand в result, потому что умножение/деление имеет более высокий приоритет.
                    LeftOperand = LeftOperand * RightOperand;
                } else if (sign == '/') {
                    LeftOperand = LeftOperand / RightOperand;
                }
                sign = currentChar;
                RightOperand = 0;
            }

        }

        result += LeftOperand; // обработка последнего числа
        return result;
    }
};
