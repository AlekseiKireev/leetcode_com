#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {

        vector<vector<int>> ans;
        int i = 0;  // encoded1's index
        int j = 0;  // encodes2's index

        while (i < encoded1.size() && j < encoded2.size()) {

            const int mult = encoded1[i][0] * encoded2[j][0];
            const int minFreq = min(encoded1[i][1], encoded2[j][1]);

            if (!ans.empty() && mult == ans.back()[0]){
                ans.back()[1] += minFreq;
            } else {
                ans.push_back({ mult, minFreq });
            }

            encoded1[i][1] -= minFreq;
            encoded2[j][1] -= minFreq;

            if (encoded1[i][1] == 0){ ++i; }                
            if (encoded2[j][1] == 0){ ++j; }
                
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> encoded1 = { {10, 2}, {7,1}, {3, 2}, {17,1} }, encoded2 = { {11, 3}, {15, 3} };

    vector<vector<int>> Ans = Solution().findRLEArray(encoded1, encoded2);

    for (auto vec : Ans) {
        for (int val : vec) {
            cout << val << ' ';
        }
        cout << '\n';
    }
}
/*
vector<vector<int>> encoded1 = { {10, 2}, {7,1}, {3, 2}, {17,1} }, encoded2 = { {11, 3}, {15, 3} };

110 2
77 1
45 2
255 1

10 10  7  3  3 17
11 11 11 15 15 15

*/
