class Solution {
public:
    void moveZeroes(vector<int>& a) {
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != 0) {
                int j = i - 1;
                while (j >= 0 && a[j] == 0) {
                    swap(a[j + 1], a[j]);
                    j--;
                }
            }
        }
    }
};
