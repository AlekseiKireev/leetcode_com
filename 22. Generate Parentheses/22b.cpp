class Solution {
public:

const int ZERO = []() { 
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 return 0;
}();

void generateParentheses(vector<char>& cur, int toOpen, int toClose, vector<string>& ans) {

    if (toOpen == 0 && toClose == 0) {
        ans.push_back(string(cur.begin(), cur.end()));
        return;
    }
    if (toOpen > 0) {
        cur.push_back('(');
        generateParentheses(cur, toOpen - 1, toClose + 1, ans);
        cur.pop_back();
    }
    if (toClose > 0) {
        cur.push_back(')');
        generateParentheses(cur, toOpen, toClose - 1, ans);
        cur.pop_back();
    }
}

// Зачем double?
// https://neerc.ifmo.ru/wiki/index.php?title=%D0%A7%D0%B8%D1%81%D0%BB%D0%B0_%D0%9A%D0%B0%D1%82%D0%B0%D0%BB%D0%B0%D0%BD%D0%B0#.D0.90.D0.BD.D0.B0.D0.BB.D0.B8.D1.82.D0.B8.D1.87.D0.B5.D1.81.D0.BA.D0.B0.D1.8F_.D1.84.D0.BE.D1.80.D0.BC.D1.83.D0.BB.D0.B0
double factorial(int n) {
    if (n == 0) {return 1;}
    else {return n * factorial(n - 1);}
}

vector<string> generateParenthesis(int n) {
    int ansSize = round(factorial(2 * n) / factorial(n) / factorial(n) / (n + 1));
    vector<string> ans; ans.reserve(ansSize);

    vector<char> cur;
    generateParentheses(cur, n, 0, ans);

    assert(ans.size() == ansSize);
    return ans;
}
};

/*
Дмитрий Козырев
​Если знать, что число скобочных последовательностей это C(2n,n)/(n+1), то можно сделать reserve у ans

Дмитрий Козырев
​Можно еще поставить assert на значение n чтобы знать насколько большое n они дали
*/
