class Solution {

/*
Сначала мы сортируем интервалы по их конечному времени. 
Это позволяет нам как можно скорее завершить текущий интервал, 
чтобы освободить место для следующего интервала.
*/

static bool comp(vector<int>& L, vector<int>& R){
    return L[1] < R[1] ;
}

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        ranges::sort(intervals, comp);

        int CurIdxMeeting = 0;
        int MaxCountMeeting = 1; // CurIdxMeeting уже состоялся, цикл начинаем со следующей встречи

        for(int i = 1; i < intervals.size(); ++i){

            if(intervals[CurIdxMeeting][1] <= intervals[i][0]){
                ++MaxCountMeeting;
                CurIdxMeeting = i;
            }
        }

        return intervals.size() - MaxCountMeeting;
    }
};
