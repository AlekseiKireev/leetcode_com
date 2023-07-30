class Solution {

    static constexpr int MaxTime = 1002;

public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {

        // CountOverlapIntervals[t] -- количество студентов делающих домашнее задание в момент времени t
        array<int, MaxTime> CountOverlapIntervals;
        CountOverlapIntervals.fill(0);

        for (int i = 0; i < startTime.size(); ++i) {

            ++CountOverlapIntervals[startTime[i]];
          
            // ввиду условия задачи можно утверждать, что в момент времени IdxEnd ученик все еще делает ДЗ, в то время как в момент времени IdxEnd + 1 уже прекратил
            --CountOverlapIntervals[endTime[i] + 1]; // из endTime[i] + 1 и "1 <= startTime[i] <= endTime[i] <= 1000" --> необходимость существ-я CountOverlapIntervals[1001] --> CountOverlapIntervals.size() == 1002 == MaxTime

        }

        for (int i = 0; i < MaxTime - 1; ++i) {
            
            CountOverlapIntervals[i + 1] += CountOverlapIntervals[i];
        }

        return CountOverlapIntervals[queryTime];
    }
};
