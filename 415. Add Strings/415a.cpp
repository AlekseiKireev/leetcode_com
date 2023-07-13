class Solution {
public:
    string addStrings(string_view al, string_view a2) {

        string res; 
        res.reserve(max(al.size(), a2.size()) + 1); 

        int carry = 0; // перенос из младшего разряда в старший

        int i1 = (int)al.size() - 1; 
        int i2 = (int)a2.size() - 1; 

        while (i1 >= 0 || i2 >= 0 || carry > 0) { 

        if (i1 >= 0) { 
            carry += al[i1] - '0'; 
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
