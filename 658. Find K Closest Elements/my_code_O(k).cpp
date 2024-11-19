/*
Time complexity: O(k+log(n))
Space complexity: O(1)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if (arr.size() == k) {
            return arr;
        }
        
        // Find the position where x would be inserted to keep the array sorted
        auto it = ranges::upper_bound(arr, x);
        int idx = it - arr.begin();
        
        // Initialize left and right pointers
        int left = idx - 1;
        int right = idx;

        // Find the k closest elements
        while (k > 0) {
            if (left < 0) {
                ++right;
            } else if (right >= arr.size()) {
                --left;
            } else if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
            --k;
        }

        // Return the k closest elements
        return vector<int>(arr.begin() + left + 1, arr.begin() + right); // +1 на случай, если вышли за гранцу, также ввиду того, что изначально сделали -1: int left = idx - 1;
    }
};
/*
arr = [1,2,3,5,11], k = 3, x = 4
Expected [2,3,5]

arr = [1,2,3,(4),5,11]

*/
/* // error on test: Input arr = [1,1,1,10,10,10] k = 1 x = 9 Output [1] Expected [10]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if (arr.size() == k) {
            return arr;
        }
        
        // Find the position where x would be inserted to keep the array sorted
        auto it = ranges::upper_bound(arr, x);
        int idx = it - arr.begin();
        
        // Initialize left and right pointers
        int left = idx;
        int right = idx;

        // Find the k closest elements
        while (k > 0) {
            if (left <= 0) {
                ++right;
            } else if (right >= arr.size()-1) {
                --left;
            } else if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
            --k;
        }

        // Return the k closest elements
        return vector<int>(arr.begin() + left , arr.begin() + right);
    }
};
*/
