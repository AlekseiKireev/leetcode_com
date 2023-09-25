#include<iostream>
#include<string_view>
#include<cassert>

using namespace std;

class Solution {

private:
    int MinLeng;
    int MaxLeng;

private:
    // insertion, deletion or substitution

    bool Replace(string_view First, string_view Second) {

        int CountDifference = 0;

        for (int i = 0; i < MinLeng; ++i) {

            CountDifference += (First[i] != Second[i]);
            if (CountDifference > 1) { return false; }
        }

        return (CountDifference == 1);

    }

    bool Delete(string_view First, string_view Second) {

        for (int i = 0; i < MinLeng; ++i) {

            if (First[i] != Second[i]) { // delete Second[i]
                return (First.substr(i) == Second.substr(i + 1));
            }
        }

        return true; // ex: abc abcd -- во втором слове удаляем d       
    }

    bool Insert(string_view First, string_view Second) {

        for (int i = 0; i < MinLeng; ++i) {

            if (First[i] != Second[i]) { // вставляем Second[i] в слово First на i позицию, все остальные буквы слова сдвигаем на "+1" вправа
                return (First.substr(i) == Second.substr(i + 1));
            }
        }

        return true; // ex: abc abcd -- в первое слово вставляем d
    }

public:

    bool isOneEditDistance(string_view First, string_view Second) {

        MinLeng = First.size();
        MaxLeng = Second.size();

        if (MinLeng > MaxLeng) { return isOneEditDistance(Second, First); }
        assert(MinLeng <= MaxLeng);

        if (MaxLeng - MinLeng > 1) { return false; }

        assert(MinLeng == MaxLeng || MinLeng == MaxLeng + 1);
        return ((MinLeng == MaxLeng) ? Replace(First, Second) : (Delete(First, Second) || Insert(First, Second)));

    }

};

/*
int main() {

    cout << Solution().isOneEditDistance("aDb", "adb") << '\n';
    cout << Solution().isOneEditDistance("ab", "ab") << '\n';
}
*/
