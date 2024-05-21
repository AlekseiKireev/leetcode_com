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

        int low = 0;
        int high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX; // max{  (x + y + 1) / 2 } = y
            assert(partitionX + partitionY == (x + y) / 2
                                ||
                   partitionX + partitionY - 1 == (x + y) / 2    
                  );
            
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
            } else {
                low = partitionX + 1;
            }

        }

        throw invalid_argument("Input arrays are not sorted.");
    }

};
