class Solution {
public:
    // O(N) time O(1) space
    int calculate(string s) {
            // https://cplusplus.com/reference/sstream/stringstream/stringstream/ -->
            // (2) initialization constructor Constructs a stringstream object with a copy of str as content.
            stringstream ss("+" + s);
        
            char op;
            int n, last, ans = 0;
            while (ss >> op >> n) { // при считывании пропускаются пробелы
                cout << op << ' ' << n << '\n';
                if (op == '+' || op == '-') {
                    n = (op == '+' ? n : -n); // определяем знак считанного числа
                    ans += n;
                } else { // можно понять на примере " 1+2 * 3 "
                    n = (op == '*' ? last * n : last / n);
                    ans = ans - last + n; 
                }
                last = n;
            }
            return ans;
    }
};
/* " 1+2 * 3 "
+ 1
+ 2
* 3
*/
