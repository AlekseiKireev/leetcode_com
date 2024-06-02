class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        const int SIZE = nums.size();

        int IdxLastNumUnique = 0;   

        for(int i = 1; i < SIZE; ++i){

            if(nums[IdxLastNumUnique] != nums[i]){
                ++IdxLastNumUnique;
                nums[IdxLastNumUnique] = nums[i];
                
            }

        } 

        return IdxLastNumUnique + 1;    
        
    }
};
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        const int SIZE = nums.size();

        int CountUnique = 1;   

        for(int i = 1; i < SIZE; ++i){

            if(nums[CountUnique - 1] != nums[i]){
                nums[CountUnique] = nums[i];
                ++CountUnique;
            }

        } 

        return CountUnique;    
        
    }
};
*/
