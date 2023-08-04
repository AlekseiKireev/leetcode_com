class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); // --> if i < j --> intervals[i][0] <=  intervals[j][0]

        vector<vector<int>> Covers;
        Covers.reserve(intervals.size());

        for(auto interval : intervals){

            if(Covers.empty() || ! /*CheckIntersection = */ (interval[0] <= Covers.back()[1])){
                Covers.push_back(move(interval));
            }else{ // CheckIntersection == true
                Covers.back()[1] = max(Covers.back()[1], interval[1]);
            }

        }

        Covers.shrink_to_fit();
        return Covers;

    }
};
