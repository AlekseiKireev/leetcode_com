class Solution {

private:
    int Ans;

    int BinarySearch(const vector<int>& a) { // https://github.com/SkosMartren/leetcode_com/tree/main/33.%20Search%20in%20Rotated%20Sorted%20Array
      
        int left = 0;
        int right = (int)a.size() - 1; // если написать "(int)a.size() - 1" будет ошибка на тесте [2,3,1] при " Ans = nums.front();"
        
        while (1 != right - left) {
                       
            int mid = left + (right - left) / 2;
            assert(mid != left && mid != right);

            int sortedLeft, sortedRight, secondLeft, secondRight;
            if (a[left] <= a[mid]) { // "<=" необходим, например, для обработки участков вида: [..., 2,2,2,2,...]
                // is_sorted({left, ..., mid}) == true
                // assert(is_sorted(a.begin() + left, a.begin() + mid + 1)); // https://en.cppreference.com/w/cpp/algorithm/is_sorted // работает, закоментировал чтобы не увеличивать расходы по памяти
                sortedLeft = left;
                sortedRight = mid;
                secondLeft = mid;
                secondRight = right;
            }
            else { // в диапозоне [mid + 1, ..., left*, ..., right] существует is_sorted({left*, ..., right}) == true
                sortedLeft = mid;
                sortedRight = right;
                secondLeft = left;
                secondRight = mid;
            }
            
                Ans = min (a[sortedLeft], Ans);
                left = secondLeft;
                right = secondRight;
            
        }

        return Ans;

    }

public:
    int findMin(vector<int>& nums) {
        Ans = nums.back(); // благодаря такой инициализации вместо "int right = (int)a.size();" можно напиать "int right = (int)a.size() - 1;"
        
        // обработка случая вида: Wrong Answer 176 / 195 Input nums = [1,3] target = 3
        // это необходимо для того, чтобы изначально в BinarySearch указатели были указаны на "int left = 0; int right = (int)a.size() - 1"        
        if(nums.size() == 2 || nums.size() == 1){return min(nums.front(), nums.back());}

        if(nums.front() < nums.back()){ // is_sorted(nums) == true
            return nums.front();
        } 

        return BinarySearch(nums);
    }
};
