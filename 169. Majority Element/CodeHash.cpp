class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> NumToCount;

        for(int num : nums){
            
            if(++NumToCount[num] > nums.size()/2){
                return num;
            }
        }
        
        return 0;
    }
};
