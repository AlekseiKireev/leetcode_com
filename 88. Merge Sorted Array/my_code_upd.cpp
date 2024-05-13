class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // необходимо слить nums2 в nums1
        int FirstPtr  = m - 1;
        int SecondPtr = n - 1;        
        int IdxMergeArray = n + m - 1;

        for(; SecondPtr >= 0; --IdxMergeArray){

            if(FirstPtr >= 0 && /*теперь гарантируется, что FirstPtr >= 0 && SecondPtr >= 0, можем сравнить элементы*/
                nums1[FirstPtr] > nums2[SecondPtr]){
                nums1[IdxMergeArray] = nums1[FirstPtr];
                --FirstPtr;    
            }else{ // FirstPtr < 0 || nums1[FirstPtr] < nums2[SecondPtr] -- в обоих случаях забираем элемент из nums2
                nums1[IdxMergeArray] = nums2[SecondPtr];
                --SecondPtr;                
            
            }
            
        }

    }
};
