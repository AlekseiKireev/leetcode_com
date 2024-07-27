/*
n  : 1 2 3 4
-> : max(SubExtr, n[i]) = n[i] --> RightPtr
<- : min(SubExtr, n[i]) = n[i] --> LeftPtr
*/

class Solution {
public:

    int findUnsortedSubarray(vector<int>& nums) {
        
        // крайний индекс, гдн нарушается условие отсортированности nums
        int RightPtr = -1; // чтобы этот индекс был крайний, необходим проход слева-направа
        int LeftPtr = -1; // чтобы этот индекс был крайний, необходим проход справа-налева

        int ExtremeSubsequance = nums.front();
        for(int i = 0; i < nums.size(); ++i){ // passing left-to-right <--> passing for finding MAX / RightPtr

            ExtremeSubsequance = max(ExtremeSubsequance, nums[i]);
            assert(nums[i] <= ExtremeSubsequance); 
            
            // проверка на нарушение сортированности nums. В случае отсортированного nums выполняется инвариант: ExtremeSubsequance == nums[i]
            if(nums[i] != ExtremeSubsequance){RightPtr = i;}

        }


        if(RightPtr == -1){return 0;} // nums is sorted
        //if(RightPtr == nums.size() - 1){return nums.size();} // Wrong Answer 277 / 307 testcases passed nums = [1,3,2,2,2]

        ExtremeSubsequance = nums.back();
        for(int i = nums.size() - 1; i >= 0; --i){ // passing right-to-left <--> passing for finding MIN / LeftPtr

            ExtremeSubsequance = min(ExtremeSubsequance, nums[i]);
            assert(ExtremeSubsequance <= nums[i]); 

            // проверка на нарушение сортированности nums. В случае отсортированного nums выполняется инвариант: ExtremeSubsequance == nums[i]
            if(ExtremeSubsequance != nums[i]){LeftPtr = i;}

        }        

        return RightPtr - LeftPtr + 1;

    }

};

/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int RightPtr = -1;
        int LeftPtr = -1;

        int ExtremeMaxFront = nums.front();
        int ExtremeMinBack  = nums.back();
        for(int i = 0; i < nums.size(); ++i){

            ExtremeMaxFront = max(ExtremeMaxFront, nums[i]);
            if(nums[i] != ExtremeMaxFront){RightPtr = i;}
            
            ExtremeMinBack = min(ExtremeMinBack, nums[nums.size() - 1 - i]);
            if(nums[nums.size() - 1 - i] != ExtremeMinBack){LeftPtr = nums.size() - 1 - i;}


        }

        if(RightPtr == -1){return 0;}
        return RightPtr - LeftPtr + 1;

    }
};
*/
