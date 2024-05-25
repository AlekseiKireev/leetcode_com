class Solution {

private:

    bool CheckIntersectionSortedIntervals(vector<int>& First, vector<int>& Second){

        return max(First.front(), Second.front()) <= min(First.back(), Second.back());
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        ranges::sort(intervals); // если не сортировать, то ошибка:  intervals = [[1,4],[0,4]] Output [[1,4]] Expected [[0,4]]
        vector<vector<int>> Ans; Ans.reserve(intervals.size());
        Ans.push_back(intervals.front());

       for(vector<int> & interval : intervals){

            if( CheckIntersectionSortedIntervals(interval, Ans.back()) ){
                Ans.back().back() = max(Ans.back().back(), interval.back());
            }else{
                Ans.push_back(interval);
            }
       }

       return Ans;
    }
};
