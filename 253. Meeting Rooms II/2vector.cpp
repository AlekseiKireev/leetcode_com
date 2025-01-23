/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int minMeetingRooms(vector<Interval> &intervals) {
        vector<int> startTimes, endTimes;

        // Extract start and end times from intervals
        for (const auto &interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }

        // Sort start and end times
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int roomsRequired = 0;
        int endPointer = 0;

        for (int i = 0; i < startTimes.size(); ++i) {
            if (startTimes[i] < endTimes[endPointer]) {
                // A new room is needed
                ++roomsRequired;
            } else {
                // One meeting ended, move the end pointer
                ++endPointer;
            }
        }

        return roomsRequired;
    }
};

/*
Сравнение startTimes[i] и endTimes[endPointer]:

Если текущая встреча начинается (startTimes[i]) раньше, 
чем заканчивается самая ранняя уже идущая встреча (endTimes[endPointer]), значит:
    У нас нет доступной комнаты (поскольку все текущие встречи еще идут).
    Требуется выделить новую комнату для этой встречи.
    Поэтому увеличиваем счетчик roomsRequired.

Случай, когда startTimes[i] >= endTimes[endPointer]:

    Это значит, что самая ранняя из текущих встреч уже завершилась к моменту начала новой встречи.
    Теперь освободилась одна комната, которую можно использовать для новой встречи.
    Мы просто сдвигаем указатель endPointer к следующей завершившейся встрече, чтобы обновить доступные комнаты.


Жадный алгоритм:

Мы минимизируем количество комнат, используя подход "сначала освобождаем, потом добавляем". 
Если комната освобождается к началу новой встречи, мы ее переиспользуем.
Это жадный метод, который работает корректно для этой задачи, так как он оптимально обрабатывает пересечения встреч.

*/
