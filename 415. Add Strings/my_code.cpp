class Solution {
public:
string addStrings(string num1, string num2) {

    try {
        unsigned long long  first = stoll(num1);
        unsigned long long  second = stoll(num2);
        return to_string(first + second);
    }
    catch (...) {

    string  intermediate_ans;  

     const int res = max(num1.size(), num2.size());
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    num1.resize(res, '0');
    num2.resize(res, '0');

    int whole_part = 0;

    for (int i = 0; i < res; ++i) {

        const int one = (num1[i] - '0');
        const int two = (num2[i] - '0');

        intermediate_ans += to_string((one + two + whole_part) % 10);
        whole_part = (one + two + whole_part) / 10;

    }
    
    reverse(intermediate_ans.begin(), intermediate_ans.end());

    if (whole_part) {
        intermediate_ans = to_string(whole_part) + intermediate_ans;
    }
return intermediate_ans;
    }
    }
};
