class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        int FIRST_SIZE = nums1.size();
        int SECOND_SIZE = nums2.size();

        ranges::sort(nums1);
        ranges::sort(nums2);

        vector<int> Intersection; Intersection.reserve(min(FIRST_SIZE, SECOND_SIZE));

        int FirstPtr = 0;
        int SecondPtr = 0;
        while(FirstPtr < FIRST_SIZE && SecondPtr < SECOND_SIZE){

            if(nums1[FirstPtr] == nums2[SecondPtr]){

                if(Intersection.empty() || Intersection.back() != nums1[FirstPtr]){
                    Intersection.push_back(nums1[FirstPtr]);
                }
                ++FirstPtr;
                ++SecondPtr;
            }else{


                (nums1[FirstPtr] < nums2[SecondPtr]) ? ++FirstPtr : ++SecondPtr;
                 
            }
        }

        return Intersection;
    }
};
