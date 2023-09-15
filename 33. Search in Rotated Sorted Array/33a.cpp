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
            if (a[left] < a[right]) {
                // sorted
                if (target < a[left] || a[right] < target) {
                    return -1;
                }
                assert(a[left] < target && target < a[right]);
                if (target < a[mid]) {
                    right = mid;
                }
                else if (target > a[mid]) {
                    left = mid;
                }
                else {
                    return mid;
                }
            }
            else {
                assert(a[left] > a[right]);
                if (target == a[mid]) {
                    return mid;
                }
                // sorted & shifted
                if (a[left] < a[mid]) {
                    // left part sorted
                    if (a[left] < target && target < a[mid]) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
                else {
                    assert(a[mid] < a[right]);
                    // right part sorted
                    if (a[mid] < target && target < a[right]) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
            }
        }
        return -1;
    }
};
