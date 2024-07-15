class Solution {
public:
    string multiply(string & num1, string & num2) {
        
        if(num1 == "0" || num2 == "0"){return "0";} 

        // reverse необхоим ввиду правила умножения в столбик: умножение происходит от младшего разряда к старшему, т.е. справа налево
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // записывать будем сюда, в начале будут младшие разряды (ввиду предыдущих reverse), в конце -- старшие
        string Answer(num1.size() + num2.size(), '0'); // num1.size() + num2.size() == MaxSizeProduct


        for(int pos1 = 0; pos1 < num1.size();++pos1){ // == num2 * num1

            const int digit1  = num1[pos1] - '0';

            for(int pos2 = 0; pos2 < num2.size();++pos2){

                const int digit2  = num2[pos2] - '0';
                const int carry =  Answer[pos1 + pos2] - '0'; // остаток
                const int BitwiseMultiplication = digit1 * digit2 + carry; // Поразрядное Умножение с учетом Остатка

                Answer[pos1 + pos2] = BitwiseMultiplication % 10 + '0'; // целая часть
                Answer[pos1 + pos2 + 1] += BitwiseMultiplication / 10; // остаток, переносится в младий разряд, но так как мы находимся в реверсивной позиции, то переносим остаток на +1
                //Answer[pos1 + pos2 + 1] =  Answer[pos1 + pos2 + 1] - '0' + BitwiseMultiplication / 10 + '0'; // переносим остаток а старший разряд
            }


        }

        if(Answer.back() == '0'){Answer.pop_back();} // проверка на ведущие нули 
        /*
        // skip leading 0's
        int i = 0;
        while (i < num.size() && num[i] == 0) ++i;
        */
        reverse(Answer.begin(), Answer.end());

        return Answer;
    }
};
