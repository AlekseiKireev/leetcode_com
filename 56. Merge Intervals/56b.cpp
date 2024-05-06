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
/* C++ 20
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        ranges::sort(intervals);
        vector<vector<int>> Ans; Ans.reserve(intervals.size());

        for(auto interval : intervals){

            
            if(Ans.empty() || /*!Intesection =*/ Ans.back().back() < interval.front()){
                Ans.push_back(interval);
            }else{
                Ans.back().back() = max(interval.back(), Ans.back().back()); // max на случай вложнности interval в Ans.back() 
            }

        }

        return Ans;
    }
};
*/

