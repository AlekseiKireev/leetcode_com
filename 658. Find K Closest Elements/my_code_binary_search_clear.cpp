class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int target) {

        function<bool(int, int)> Operator = [target](const int a, const int b) {
            return target - a > b - target;
        };

        int left = 0;
        int right = (int)arr.size() - k;

        while (1 != right - left + 1) {

            const int mid = left + (right - left) / 2;

            Operator(arr[mid], arr[mid + k]) ? left = mid + 1 : right = mid;

        }

        return {arr.begin() + left, arr.begin() + left + k};
    }

};
