#include <vector> 
#include <cassert> 
#include <climits> 
#include <stdexcept>
#include <iostream>

using namespace std;


class Solution{

bool sumGreater(int a, int b, int c) { // a + b > c
    
    if (b > 0 && a > INT_MAX - b) {return true;}
    
    if (b < 0 && a < INT_MIN - b) {return false;}
    
    return a + b > c;
}

bool sumEquals(int a, int b, int c) { // a + b == c
    
    if (b > 0 && a > INT_MAX - b) {return false;}
    
    if (b < 0 && a < INT_MIN - b) {return false;}
    
    return a + b == c;
}

public:

    vector<int> twoSum(const vector<int>& a, int target) {

        int j = (int)a.size() - 1;
        for (int i = 0; i < (int)a.size(); i++) {

            while (j >= 0 && sumGreater(a[i], a[j], target)) { j--; }

            assert(i < j);

            if (sumEquals(a[i], a[j], target)) {
                return { i + 1, j + 1 };
            }

        }

        throw invalid_argument("no sum target");
    }

};


int main() {

    cout << Solution().twoSum({ 1,2,INT_MAX }, 3)[0] << ' ' << Solution().twoSum({ 1,2,INT_MAX }, 3)[1] << '\n'; // 1 2
    cout << Solution().twoSum({ INT_MIN, -1,-2 }, -3)[0] << ' ' << Solution().twoSum({ INT_MIN, -1,-2 }, -3)[1] << '\n'; // 2 3

    return 0;
}
