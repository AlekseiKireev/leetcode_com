#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    long long n, k; cin >> n >> k;
    string s; cin >> s;

    int Cnt_a_InSW = 0, Cnt_b_InSW = 0; // количество символов в [l,..,r]
    int ans = 0;
    long long CntPair = 0; // количество пар (i, j) таких что l <= i < j <= r и s[i] = a, s[j] = b 

    for (int l = 0, r = 0; r < n; ++r) {
        
        if (s[r] == 'a') {
            Cnt_a_InSW++;
        } 
        if (s[r] == 'b') { // 
            Cnt_b_InSW++;
            CntPair += Cnt_a_InSW;
        }

        for (;CntPair > k; l++) {
            if (s[l] == 'a') {
                Cnt_a_InSW--;
                CntPair -= Cnt_b_InSW;
            } 
            if (s[l] == 'b') {
                Cnt_b_InSW--;
            }
            
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;
    return 0;
}
