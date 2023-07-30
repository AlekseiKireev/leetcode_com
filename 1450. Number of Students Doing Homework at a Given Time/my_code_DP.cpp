class Solution {

public:

    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {

        // CountOverlapIntervals[t] -- количество студентов делающих домашнее задание в момент времени t
        array<int, 1002> CountOverlapIntervals; 
        CountOverlapIntervals.fill(0);

        for (const int IdxStart : startTime) {
          
            CountOverlapIntervals[IdxStart] += 1;
        }

        for (const int IdxEnd : endTime) {
          
            // ввиду условия задачи можно утверждать, что в момент времени IdxEnd ученик все еще делает ДЗ
            // в то время как в момент времени IdxEnd + 1 уже прекратил
            CountOverlapIntervals[IdxEnd + 1] -= 1;
        }

        for (int i = 0; i < 1001; i++) { // 0 <= i <= 1000

            // из i+1 и "1 <= startTime[i] <= endTime[i] <= 1000" --> необходимость существ-я CountOverlapIntervals[1001] --> CountOverlapIntervals.size() == 1002
            CountOverlapIntervals[i + 1] += CountOverlapIntervals[i];
        }

        return CountOverlapIntervals[queryTime];
    }

};
