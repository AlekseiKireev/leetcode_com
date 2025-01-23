class Solution {
private:
    struct Event {
        int time;
        int type; // 1 for start, -1 for end
    };

    friend bool operator<(const Event &lhs, const Event &rhs) {
        return (lhs.time == rhs.time) ? (lhs.type < rhs.type) : (lhs.time < rhs.time);
    }

public:

    int minMeetingRooms(vector<Interval> &intervals) {
        vector<Event> events;
        events.reserve(2 * intervals.size());

        for (const auto &interval : intervals) {
            events.push_back({interval.start, 1});  // Start of a meeting
            events.push_back({interval.end, -1});  // End of a meeting
        }

        sort(events.begin(), events.end());

        int minRooms = 0, currentRooms = 0;

        for (const auto &event : events) {
            currentRooms += event.type; // Increment or decrement based on type
            minRooms = max(minRooms, currentRooms); // Update the maximum rooms needed
        }

        return minRooms;
    }
};
