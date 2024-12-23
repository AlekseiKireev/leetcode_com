#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    long long n, k; cin >> n >> k;
    string s; cin >> s;

    int cnta = 0, cntb = 0;
    int ans = 0;
    long long sum = 0;

    for (int l = 0, r = 0; r < n; ++r) {
        
        if (s[r] == 'a') {
            cnta++;
        } 
        if (s[r] == 'b') {
            cntb++;
            sum += cnta;
        }

        for (;sum > k; l++) {
            if (s[l] == 'a') {
                cnta--;
                sum -= cntb;
            } 
            if (s[l] == 'b') {
                cntb--;
            }
            
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;
    return 0;
}
