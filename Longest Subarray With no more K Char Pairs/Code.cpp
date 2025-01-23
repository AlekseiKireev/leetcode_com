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
        if (s[r] == 'b') { // в окне [l,..,r] символ 'a' встречается Cnt_a_InSW раз, с каждым из них символ 'b' может образовать пару
            Cnt_b_InSW++;
            CntPair += Cnt_a_InSW;
        }

        for (;CntPair > k; l++) { // не выполняется улосвие задачи: "количество пар (i, j) не превосходит числа k"
            if (s[l] == 'a') { // т.к. рассматриваем пары {s[i] = a, s[j] = b  : i < j}, то при смещение левого указателя, указываещго на 'a', колич-о пар уменьш-я на Cnt_b_InSW
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
