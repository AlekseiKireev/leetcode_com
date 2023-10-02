//#include <iostream>
//#include <vector>
//#include<algorithm>
//
//using namespace std; 

class Solution {

private:

    struct Event {

        int Val;
        int Type;

    };

    friend bool operator<(const Event L, const Event R) {
        return (L.Val == R.Val ? L.Type < R.Type : L.Val < R.Val);
    }

private:

    int MNCR = 0; // Minimum Number of Conference Rooms 

public:

    int minMeetingRooms(vector<vector<int>>& intervals) {

        const int COUNT_INTERVALS = intervals.size();
        vector<Event> events; events.reserve(2 * COUNT_INTERVALS); // "2 * " <-- укладывания концов в intervals в events 

        // for (int i = 0; i < intervals.size(); ++i) { // error!
        for (int i = 0; i < COUNT_INTERVALS; ++i) {

            const auto event = intervals.back();
            intervals.pop_back();
            events.push_back({ event.front(), 1 });
            events.push_back({ event.back(), -1 });

        }

        sort(events.begin(), events.end());

        int CurrentNCR = 0;

        for (const auto [val, type] : events) {
            CurrentNCR += type;
            MNCR = max(MNCR, CurrentNCR);
        }


        return MNCR;

    }

};

/*

вопрос: почему если конструкцию

    struct Event {

        int Val;
        int Type;

    };

    const bool operator<(const Event L, const Event R) {
        return (L.Val == R.Val ? L.Type < R.Type : L.Val < R.Val);
    }

держать в приватной секции, будет ошибка too many parameters for this operator function

А если вынести ее из класса Solution, то ошибка исчезает?



Потому что внутри класса по-умолчанию объявляются member function с неявным параметром this. Получается три параметра: this, L, R; можно объявить её friend
https://en.cppreference.com/w/cpp/language/operator_comparison
*/
