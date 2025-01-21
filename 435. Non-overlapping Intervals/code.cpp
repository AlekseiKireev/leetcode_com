class Solution {

/*
Сначала мы сортируем интервалы по их конечному времени. 
Это позволяет нам как можно скорее завершить текущий интервал, 
чтобы освободить место для следующего интервала.

This sorting is crucial because it allows us to prioritize intervals that finish early, 
giving us more opportunities to accommodate additional meetings later on.
*/

static bool comp(vector<int>& L, vector<int>& R){
    return L[1] < R[1];
}

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        ranges::sort(intervals, comp);

        // Индекс последнего добавленного в множество не пересекающихся интервалов
        int CurIdxMeeting = 0; // intervals[CurIdxMeeting] оканчивается раньше всех, следовательно, начинается раньше всех
        
        // максимальное количество встреч, которое можно провести
        int MaxCountMeeting = 1; // intervals[CurIdxMeeting] уже состоялся, цикл начинаем со следующей встречи, т.е. 1

        for(int i = 1; i < intervals.size(); ++i){

            if(intervals[CurIdxMeeting][1] <= intervals[i][0]){ // intervals[CurIdxMeeting] и ntervals[i] не пересекаются
                                                                // при этом intervals[i] заканчивается раньше intervals[i+1]
                ++MaxCountMeeting;
                CurIdxMeeting = i;
            }
        }

        return intervals.size() - MaxCountMeeting; // минимальное количество встреч, которые надо удалить, чтобы провести макисмальное количество встреч
    }
};
