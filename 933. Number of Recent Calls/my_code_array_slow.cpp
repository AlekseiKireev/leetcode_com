class RecentCounter {

private:
    static const int NUMBER_MILISECONDS = 3001;
    array<int, NUMBER_MILISECONDS> Pings;
    array<int, NUMBER_MILISECONDS> Count;

public:
    RecentCounter() {
        Pings.fill(0);
        Count.fill(0);
    }
    
    int ping(int t) {
        Pings[t%NUMBER_MILISECONDS] = t;
        Count[t%NUMBER_MILISECONDS] = 1;

        int countHits = 0;

        for (int i = 0; i < NUMBER_MILISECONDS; ++i){
            if (NUMBER_MILISECONDS + Pings[i] >= t){
                countHits += Count[i];
            }
        }

        return countHits;        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
