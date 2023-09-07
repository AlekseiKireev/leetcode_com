class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i = 0; // откуда пишем
        while (i < (int)a.size() && a[i] != 0) {
            i++;
        }
        int j = i; // куда пишем
        for (; i < (int)a.size(); i++) {
            if (a[i] != 0) {
                a[j] = a[i];
                j++;
            }
        }
        for (; j < (int)a.size(); j++) {
            a[j] = 0;
        }
    }
};
