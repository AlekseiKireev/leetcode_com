class Solution {
public:
    string addStrings(const string & a1, const string & a2) {//string addStrings(string_view a1, string_view a2) { // good!

        string res; 
        res.reserve(max(a1.size(), a2.size()) + 1); 

        int carry = 0; // перенос из младшего разряда в старший

        // индексы на младшие разряды слагаемых, так как складыватся будут цифры чисел от младших разрядов к старшим
        int i1 = (int)a1.size() - 1; 
        int i2 = (int)a2.size() - 1; 

        while (i1 >= 0 || i2 >= 0 || carry > 0) { 

            if (i1 >= 0) { // проверка необходима так как может быть i1 < 0, в то времия как i2 >= 0
                carry += a1[i1] - '0'; 
                i1--;
            }
    
            if (i2 >= 0) { 
                carry += a2[i2] - '0'; 
                i2--;
        } 

        res.push_back(char(carry % 10 + '0')); 
        carry /= 10; 
        }

        assert(i1 < 0 && i2 < 0 && carry == 0); 

        reverse(res.begin(), res.end()); 
        assert(res.size() == 1 || (res.size() > 1 && res[0] != '0')); 
        return res; 
    }
};
