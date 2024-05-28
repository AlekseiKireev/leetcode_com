class RecentCounter {

private:

queue<int> Pings;

private:

    void clear(int timestamp) {
        // необходимы события, находящиеся в [timestamp - 3000, timestamp]   
        while(/*Pings.empty() == false && */Pings.front() <  timestamp - 3000){ // пустым не будет, так как сверху лежит гарантировано timestamp
            Pings.pop();
        }
    }

public:
    RecentCounter() {}
    
    int ping(int t) {
        Pings.push(t);
        clear(t);
        return Pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
