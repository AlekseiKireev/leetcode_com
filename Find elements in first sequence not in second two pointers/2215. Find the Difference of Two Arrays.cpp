class Solution {
    std::vector<int> findElementsNotInSecond(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;

            } else if (nums1[i] == nums2[j]) {

                const int equiv = nums1[i];
                /*
                    Без циклов ошибка будет в тесте:
                    [1,1,2,2]
                    [1,2,3,3]
                */
                while(i < nums1.size() && nums1[i] == equiv){i++;}
                while(j < nums2.size() && nums2[j] == equiv){j++;}

            } else {

                j++;
            }
        }

        // Если остались элементы в nums1, которые не были проверены
        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }

        return result;
    }

public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> unique_nums1 = findElementsNotInSecond(nums1, nums2);
        std::vector<int> unique_nums2 = findElementsNotInSecond(nums2, nums1);
        // Оставляем только уникальные элементы для unique_nums2

        unique_nums1.erase(std::unique(unique_nums1.begin(), unique_nums1.end()), unique_nums1.end());
        unique_nums2.erase(std::unique(unique_nums2.begin(), unique_nums2.end()), unique_nums2.end());

        return {unique_nums1, unique_nums2};
    }
};
