class Solution {

const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();

public:
int search(const vector<int>& a, int target) {

    int left = 0;

    int right = (int)a.size() - 1; // чтобы на пустом массиве нормально отбработал, кастуем к int: (int)a.size() - 1, иначе -- переполнение

    // answer maybe in [left; right]

    while (left <= right) {

        int mid = (left + right) / 2;

        if (target > a[mid]) {

            left = mid + 1;

        }
        else if (target < a[mid]) {

            right = mid - 1;

        }
        else {

            return mid;

        }
    }

    return -1;

}
};

