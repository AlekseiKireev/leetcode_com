/*
class Solution {
 public:
  vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
  }
};
*/

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {

public:

    /*
    
    1 <= val_i, freq_i <= 10^4 for each encoded1[i].
    1 <= val_j, freq_j <= 10^4 for each encoded2[j].
    
    encoded1[i].front() == val_i, encoded1[i].back() == freq_i
    encoded2[j].front() == val_j, encoded2[j].back() == freq_j
    */
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {  

        vector<vector<int>> Product;

        int i = 0;
        int j = 0;

        while (i < encoded1.size()) { // <-- "The full arrays that encoded1 and encoded2 represent are the same length." --> sum(freq_i) == sum(freq_j)

            /*
            encoded1[i].length == 2
            encoded2[j].length == 2
            */
            int product_ij = encoded1[i].front() * encoded2[j].front();

            // "Note: Compression should be done such that the run-length encoded array has the minimum possible length."
            int freq_ij = min(encoded1[i].back(), encoded2[j].back()); // количество  product_ij не может быть более min(encoded1[i].back(), encoded2[j].back())

            encoded1[i].back() -= freq_ij;
            encoded2[j].back() -= freq_ij;

            // хотя бы один из этих условных операторов сработает всегда ввиду определения freq_ij, а в конечном итоге i AND j одновременно укажут на i == encoded1.size() AND j == encoded2.size() --> цикл будет работать за O(|encoded1| + |encoded2|)
            if (encoded1[i].back() == 0) { ++i; }
            if (encoded2[j].back() == 0) { ++j; }

            Product.push_back({ product_ij , freq_ij });
        }

        return Product;

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
