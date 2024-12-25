class Solution {
public:
    bool check(const string& s) {
        int n = s.size();

        if (n == 1) {return true;}
        if (n > 3 || s[0] == '0') {return false;}

        int val = stoi(s);
        return val <= 255;
    }

    vector<string> restoreIpAddresses(string s) {

        int n = s.size();
        vector<string> ans;
        if (n > 12 || n < 3) {return ans;}

        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    
                    // p = i + j + k -- индекс, с которого начинается последний чанк
                    // n - 1 -- последний индекс, тогда колич-о элементов в посл. чанке:
                    // n - 1 - p + 1 = n-p
                    if (1 <= n - (i + j + k)
                        && 
                        n - (i + j + k) <= 3
                        ) {
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i + j, k);
                        string d = s.substr(i + j + k);

                        if (check(a) && check(b) && check(c) && check(d)) {
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
                        
                    }
                }
            }
        }

        return ans;
    }
};
