/*
Time complexity: O(n*log(n) + m*log(m))
Space complexity: O(n+m)
*/
class Solution {

    std::vector<int> findElementsNotInSecond(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] < nums2[j]) {

                if(result.empty() || result.back() != nums1[i]) { /* отличие от https://github.com/SkosMartren/leetcode_com/tree/main/Find%20elements%20in%20first%20sequence%20not%20in%20second%20two%20pointers
                                                                     в этом условном операторе*/
                    result.push_back(nums1[i]);
                }

                i++;

            }  else if (nums1[i] == nums2[j]) {

                const int equiv = nums1[i];
                /*
                    Без циклов ошибка будет в тесте:
                    [1,1,2,2]
                    [1,2,3,3]
                */
                while(i < nums1.size() && nums1[i] == equiv){i++;}
                while(j < nums2.size() && nums2[j] == equiv){j++;}

            } 
            
            else if (nums1[i] > nums2[j]) {

                j++;
            }
        }

        // Если остались элементы в nums1, которые не были проверены
        for (;i < nums1.size();i++) {
            
                if(result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
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
