class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> Triplets;

        sort(nums.begin(), nums.end());

        if(nums.front() > 0 || nums.back() < 0 ){return Triplets;}

        for(int i = 0; i < nums.size(); ++i){

        }

        return Triplets;
    }
};
