class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int l = 0, r = arr.size() - 1;
        while (r - l + 1 != k) {
            assert(l < r);
            if (x - arr[l] <= arr[r] - x) {
                --r;
            } else {
                ++l;
            }
        } // l и r указывают на концы искомого вектора --> при возврате надо дописать " + 1"

        return vector<int>(arr.begin() + l, arr.begin() + r + 1);
    }
};
