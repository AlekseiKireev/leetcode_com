class Solution {

bool isPalindrome(const string& S)
{

    for (int i = 0; i < S.size() / 2; i++) {

        if (S[i] != S[S.size() - i - 1]) {return false;}
    }

    return true;
}

public:
    string longestPalindrome(const string& s) {
        
        string LPS  {s.front()}; // <-- "1 <= s.length <= 1000"

        for (int i = 0; i < s.size(); i++) {
                for (int j = i + 1; j <= s.size(); j++) {
                    
                    if(isPalindrome({s.begin() + i, s.begin() + j}) && LPS.size() < j - i){
                       LPS = {s.begin() + i, s.begin() + j};
                    }
            }
        }

        return LPS;
    }
};
/* // примечательно, что такой код на JS работает
const isPalidrom = (s) => {
    let l = 0
    let r = s.length - 1
    while (l < r) {
        if (s[l] !== s[r]) return false
        l++
        r--
    }
    return true
}

function longestPalindrome(s )  {
    let longest = s[0]
    for (let i = 0; i < s.length; i++) {
        let right = s.length - 1
        while (i < right) {
            const curStr = s.slice(i, right + 1)
            if (isPalidrom(curStr)) {
                if (longest.length < curStr.length) longest = curStr
            }
            right -= 1
        }
    }
    return longest
};
*/
