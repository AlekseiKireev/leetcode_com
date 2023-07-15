class Solution {

    // вместо long long* можно использовать тип auto, если затруднительно указать тип
    long long* getKoef() {
        static long long koef[1 + 'z'] = {};
        if (koef[0] == 0) {
            mt19937 gen(2202);
            for (char c = 'a'; c <= 'z'; c++) {
                koef[c] = uniform_int_distribution<long long>(1e14, 2e14)(gen);
            }
        }
        return koef;
    }

public:

    vector<int> findAnagrams(string_view s, string_view p) {
        
        if (s.size() < p.size()) {return {};}
        
        vector<int> ans;
        long long* koef = getKoef();
        
        long long sum = 0; // char of p -, chars of s +, multiply by koef 
        
        for (char c : p) {
            sum -= koef[c];
        }
        
        for (int i = 0; i < (int)p.size(); i++) {
            const char c = s[i];
            sum += koef[c];
        }
        
        if (sum == 0) {ans.push_back(0);}
        
        for (int i = (int)p.size(); i < (int)s.size(); i++) {
            char toRemove = s[i - (int)p.size()];
            char toAdd = s[i];
            sum -= koef[toRemove];
            sum += koef[toAdd];
            if (sum == 0) {
                ans.push_back(i - (int)p.size() + 1);
            }
        }
            return ans;
    }
    
};
