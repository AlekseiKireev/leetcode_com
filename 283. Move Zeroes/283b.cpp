class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i = 0; // откуда пишем
        while (i < (int)a.size() && a[i] != 0) {
            i++;
        } // i указывает на первый ноль в входных данных
        int j = i; // куда пишем
        for (; i < (int)a.size(); i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};
