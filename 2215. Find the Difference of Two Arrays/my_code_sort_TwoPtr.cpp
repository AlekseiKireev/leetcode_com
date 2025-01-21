/*
Time complexity: O(n*log(n) + m*log(m))
Space complexity: O(n+m)
*/
class Solution {

    std::vector<int> findElementsNotInSecond(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> result;
        int Ptr_1 = 0, Ptr_2 = 0;

        while (Ptr_1 < nums1.size() && Ptr_2 < nums2.size()) {

            if (nums1[Ptr_1] < nums2[Ptr_2]) {

                if(result.empty() || result.back() != nums1[Ptr_1]) { /* отличие от https://github.com/SkosMartren/leetcode_com/tree/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers
                                                                     в этом условном операторе*/
                    result.push_back(nums1[Ptr_1]);
                }

                Ptr_1++;

            }  else if (nums1[Ptr_1] == nums2[Ptr_2]) {

                const int equiv = nums1[Ptr_1];
                /*
                    Без циклов ошибка будет в тесте:
                    [1,1,2,2]
                    [1,2,3,3]

                    Также тут заметно отличие от https://github.com/SkosMartren/leetcode_com/tree/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers
                */
                while(Ptr_1 < nums1.size() && nums1[Ptr_1] == equiv){Ptr_1++;}
                while(Ptr_2 < nums2.size() && nums2[Ptr_2] == equiv){Ptr_2++;}

            } 
            
            else if (nums1[Ptr_1] > nums2[Ptr_2]) {

                Ptr_2++;
            }
        }

        // Если остались элементы в nums1, которые не были проверены
        for (;Ptr_1 < nums1.size();Ptr_1++) {
            
                if(result.empty() || result.back() != nums1[Ptr_1]) {
                    result.push_back(nums1[Ptr_1]);
                }            
            
        }

        return result;
    }

public:

    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());               

        return {findElementsNotInSecond(nums1, nums2), findElementsNotInSecond(nums2, nums1)};
    }
};
