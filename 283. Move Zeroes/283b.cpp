class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i = 0;
        while (i < (int)a.size() && a[i] != 0) {
            i++;
        }
        int j = i;
        for (; i < (int)a.size(); i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};
