class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    /*
    "
The final sorted array should not be returned by the function, but instead be stored inside the array nums 1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
    "
    */

    assert(nums1.size() == m + n);

    /*
    Ввиду комментария выше можно утверждать, что как только все элементы из nums2 будут перемещены в nums1
    работа алгоритма будет остановлена.

    while(nums2FullyInspected == false){
        if( comp(nums1[Ptr1], nums2[Ptr2]) ){
            nums1[i] = nums2[Ptr2];
            --Ptr2;
            
        }else{
            nums1[i] = nums1[Ptr1];
            --Ptr1;
        }
        move(i);
    }

    0 <= i <=  m + n - 1
    0 <= Ptr1 <= m - 1
    0 <= Ptr2 <= n - 1
    i / Ptr1 / Ptr2 изначальна указывают на одно и то же стартовое положение, вопрос: какое именно? begin или prev(end)?
    
    Ввиду my_example --> prev(end) -- действительно, первые два элемента в nums1 нет смысла перекладвать, 
    можно построить аналогичый пример, где большой префикс nums1 будет оставаться на месте

    Заметим, что и примеров
    nums1 = [1,2,3],  nums2 = [4,5,6]
    nums1 = [4,5,6],  nums2 = [1,2,3]

    следует необходимость контролировать как Ptr1, так и Ptr2 на >= 0
    */

    int Ptr1 = m - 1;
    int Ptr2 = n - 1;
    
    int Idx = m + n - 1;

    while(Ptr2 >= 0){

        if(Ptr1 >= 0 && nums2[Ptr2] < nums1[Ptr1]){

            nums1[Idx] = nums1[Ptr1];
            --Ptr1;

        }else {
            nums1[Idx] = nums2[Ptr2];
            --Ptr2;
        }
        --Idx;

    }
  }
};
