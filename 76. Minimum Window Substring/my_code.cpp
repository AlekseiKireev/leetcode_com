class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        std::vector<int> map(128, 0);
        
        for (char c : t) {
            map[c]++;
        }


        int count = t.length(),  MinLenSubstring = INT_MAX, LeftPtrIndexSubstring = 0;

        for (int LeftPtr = 0, RightPtr = 0;RightPtr < s.length();RightPtr++) { // сдвиг правого указателя
            
            if (map[s[RightPtr]] > 0) {
                count--;
            }
            map[s[RightPtr]]--;


            for (;count == 0;LeftPtr++) { // сдвиг левого указателя

                if (RightPtr - LeftPtr < MinLenSubstring) { // обновление искомой Substring
                    LeftPtrIndexSubstring = LeftPtr;
                    MinLenSubstring = RightPtr - LeftPtr;
                }

                if (map[s[LeftPtr]] == 0) { // s[LeftPtr] один из символов t
                    count++;

                    // необходимо в любом случае сдвигать, а не только в момент захода в условный оператор
                    //map[s[LeftPtr]]++; // Wrong Answer 180 / 268 testcases passed Input s = "ADOBECODEBANC" t = "ABC" Output "ANC" Expected "BANC"
                }

                map[s[LeftPtr]]++;
                
            }            

        }

        return MinLenSubstring == INT_MAX ? "" : s.substr(LeftPtrIndexSubstring, MinLenSubstring + 1);
    }
};
