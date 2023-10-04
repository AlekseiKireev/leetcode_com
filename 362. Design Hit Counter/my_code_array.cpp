

class HitCounter {

private:
// https://github.com/SkosMartren/leetcode_com/blob/main/README.md#setting-the-size-of-an-array-in-a-private-section
static constexpr int NUMBER_SECONDS = 300;

public:

    HitCounter() {
        timestamps.fill(0);
        hits.fill(0);
    }

    void hit(int timestamp) { // "All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing)."

        const int i = timestamp % 300;
        timestamps[i] = timestamp;
        hits[i] = 1; 
        
    }

    int getHits(int timestamp) {
        int countHits = 0;

        for (int i = 0; i < 300; ++i) {
            if (timestamp - timestamps[i] < 300) { countHits += hits[i]; }
        }

        return countHits;
    }

private:
    array<int, NUMBER_SECONDS> timestamps;
    array<int, NUMBER_SECONDS> hits;
};
