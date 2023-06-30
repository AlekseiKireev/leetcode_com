class Solution {
public:
vector<string> summaryRanges(const vector<int>& nums) {
 
    vector<string> ans;
 
    for (int i = 0; i < nums.size(); ++i) {
 
        int start_ranges = nums[i];
        //  nums[i] < nums[i+1] --> в 1 + nums[i] переполнения не будет, в то
        // время как в nums[i + 1]  - nums[i]  будет 
        while (i + 1 < nums.size() && nums[i + 1] == 1 + nums[i] ) { ++i; } 
 
        if (start_ranges != nums[i]) {
            ans.push_back(to_string(start_ranges) + "->" + to_string(nums[i]));
        }
        else {
            ans.push_back(to_string(start_ranges));
        }
 
 
    }
 
    return ans;
}


};
