class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;

        for (;i < n && intervals[i][1] < newInterval[0]; i++) {
            res.push_back(intervals[i]);            
        }

        for (; i < n && intervals[i][0] <= newInterval[1]; i++) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);            
        }
        res.push_back(newInterval);

        for (;i < n; i++) {
            res.push_back(intervals[i]);            
        }
        
        return res;
    }
};
