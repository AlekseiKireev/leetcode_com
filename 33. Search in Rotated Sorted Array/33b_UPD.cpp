class Solution {
public:
    int search(const vector<int>& a, int target) {

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
        while (1 != right - left) {
                       
            int mid = (left + right) / 2;
            assert(mid != left && mid != right);
            int sortedLeft, sortedRight, secondLeft, secondRight;
            if (a[left] < a[mid]) { // is_sorted({left, ..., mid}) == true
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
            
            if (a[sortedLeft] <= target && target < a[sortedRight]) { // target <= a[sortedRight] ошибочен, так как может наружать инвариант: a[left] <= target
                left = sortedLeft;
                right = sortedRight;
            }
            else {
                left = secondLeft;
                right = secondRight;
            }

            if(a[left] == target) {return left;}
        }

        return -1;

    }
};
