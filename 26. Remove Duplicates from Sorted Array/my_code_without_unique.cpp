    int removeDuplicates(vector<int>& nums) {

        long long CountDuplicates = 0;
        for(int i = 1; i < nums.size();++i){

            if(nums[i - 1] != nums[i]){ // смещаем влево. CountDuplicates -- значение того, насколько надо смещать
                /*Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. */
                // 1 2 3 3 3 4 5 6 6 7 --> 1 2 3 _ _ 4 5 6 6 7 --> 1 2 3 4 5 6 7 _ _ _
                nums[i-CountDuplicates] = nums[i]; // 1 3 2 2 4 5 --> 1 3 2 4 5 _
            }
            else{ //nums[i] == nums[i-1]
                ++CountDuplicates;
            }
        }

        return nums.size() - CountDuplicates;
    }


/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int CountUniqueInPrefix = 1; // nums.front() однозначно уникальный

        for(int i = 1; i < nums.size(); ++i){

            if(nums[i] != nums[i-1]){
                //Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
                nums[CountUniqueInPrefix] = nums[i]; // Input nums = [1,1,2]  Output [1,1] Expected [1,2]
                ++CountUniqueInPrefix;
            }
        }

        return CountUniqueInPrefix;
    }
};
*/
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int CurUpdidx = 1;

        for(int i = 0; i < nums.size(); ++i){

            if(nums[i] != nums[CurUpdidx - 1]){
                nums[CurUpdidx] = nums[i];
                ++CurUpdidx;
                
            }
        }

        return CurUpdidx;
    }
};
*/
