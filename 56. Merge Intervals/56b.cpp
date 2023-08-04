class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) { return intervals; } // 1 <= intervals.length <= 10^4

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        ans.push_back(move(intervals[0]));

        for (int i = 1; i < (int)intervals.size(); i++) {

            if (intervals[i][0] <= ans.back()[1]) {

                // // max for 117 / 170 testcases passed: [[1,4],[2,3]]
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(move(intervals[i]));
            }
        }

        return ans;
    }
};
