class RecentCounter {

private:

vector<int> Pings; // int <-- "1 <= t <= 10^9"

public:
    RecentCounter() { // "At most 10^4 calls will be made to ping."
        Pings.reserve(1e4);
    }
    
    int ping(int t) {

        Pings.push_back(t);

        // "Each test case will call ping with strictly increasing values of t."
        return Pings.end() - lower_bound(Pings.begin(), Pings.end(), t - 3000);
    }

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
