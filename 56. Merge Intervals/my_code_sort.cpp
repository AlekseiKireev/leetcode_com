class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> Covers;
        Covers.reserve(intervals.size());

        int StartCover = intervals.front().front();
        int EndCover = intervals.front().back();

        for(auto interval : intervals){

            int StartCover_i = interval.front();
            int EndCover_i = max(EndCover, interval.back());


            // start1 <= finish2 and start2 <= finish1
            const bool CheckIntersection = StartCover_i <= EndCover && StartCover <= EndCover_i; 
            
            if(CheckIntersection){
                
                // max for 117 / 170 testcases passed: [[1,4],[2,3]]
                EndCover = max(interval.back(), EndCover);

            }else{

                Covers.push_back({StartCover, EndCover});

                StartCover = StartCover_i;
                EndCover = max(EndCover, EndCover_i);
            }
            
        }

        Covers.push_back({StartCover, EndCover});
        Covers.shrink_to_fit();
        return Covers;

    }
};
