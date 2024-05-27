// https://www.youtube.com/watch?v=LPFhl65R7ww

class Solution {
public:

    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        assert(x <= y);

        // далее следует бинарный поиск по массиву меньшей длины
        int low = 0;
        int high = x; // x-1 --> RE. Дейтвитнельно, такое значение нужно на случай, если low = x-1 --> 0 <= partitionX <= x

        while (low <= high) { // equiv: while (0 != high - low + 1) {
            int partitionX = (low + high) / 2; // берутся элементы слева от partitionX
            // " + 1" необходим для того, чтобы слева от оазделителей было на один элемент больше чем справа, это удобно для получения медианы 
            int partitionY = (x + y + 1) / 2 - partitionX; // max{  (x + y + 1) / 2 } = y

            // суммарное коли-о элементов слева от partitionX partitionY равно:
            assert(partitionX + partitionY == (x + y) / 2
                                ||
                   partitionX + partitionY == (x + y) / 2 + 1
                  );

            // Если partition == 0, слева от него нет элементов, вносим виртуальный элемент INT_MIN
            // Если partition == container.size(), справа от него нет элементов, вносим виртуальный элемент INT_MAX
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {


                
                return ( (x + y) % 2 == 0 ) ?
                     (double)( max(maxLeftX, maxLeftY) + min(minRightX, minRightY) ) / 2
                        :
                     (double)max(maxLeftX, maxLeftY);
                
            } 

            // нарушино что-то из: maxLeftX <= minRightY && maxLeftY <= minRightX
            if (maxLeftX > minRightY) { 
                // необходимо приблизиться к выполнению условия: maxLeftX <= minRightY
                high = partitionX - 1;
                //high = partitionX; // working!
            } else { // нарушение в maxLeftY <= minRightX, т.е. maxLeftY > minRightX --> надо уменьшить maxLeftY
                low = partitionX + 1;
            }

        }

        throw invalid_argument("Input arrays are not sorted.");
    }

};
