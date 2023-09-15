class Solution {
public:
    int search(const vector<int>& a, int target) {
        if (a.empty()) {
            return -1;
        }
        if (a[0] == target) {
            return 0;
        }
        if (a.size() == 1) {
            return -1;
        }
        if (a.back() == target) {
            return (int)a.size() - 1;
        }
        int left = 0;
        int right = (int)a.size() - 1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            assert(mid != left && mid != right);
            int sortedLeft, sortedRight, secondLeft, secondRight;
            if (a[left] < a[mid]) {
                sortedLeft = left;
                sortedRight = mid;
                secondLeft = mid;
                secondRight = right;
            }
            else {
                sortedLeft = mid;
                sortedRight = right;
                secondLeft = left;
                secondRight = mid;
            }
            if (a[sortedLeft] <= target && target <= a[sortedRight - 1]) {
                left = sortedLeft;
                right = sortedRight;
            }
            else {
                left = secondLeft;
                right = secondRight;
            }
        }
        if (a[left] == target) {
            return left;
        }
        else {
            return -1;
        }
    }
};
