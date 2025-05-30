/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    string reverseWords(string& s) {
        
        auto LeftPtr = s.begin();

        for(auto RightPtr = LeftPtr + 1; RightPtr != s.end(); ++RightPtr){

            if(*RightPtr == ' '){
                reverse(LeftPtr, RightPtr);
                LeftPtr = RightPtr + 1;
            }
        }

        reverse(LeftPtr, s.end()); /* на случай если в слове нет пробела. Также чтобы это работало надо удалять пробелы с конца s
                                      The input must not contain any leading or trailing spaces. -- вывод на тесте "Let's take LeetCode contest         "*/
        return s;

    }
};
