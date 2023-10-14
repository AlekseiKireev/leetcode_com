#include <iostream>
#include <array>

using namespace std;

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

        const int i = timestamp % NUMBER_SECONDS;

        if (timestamps[i] == timestamp) {
            ++hits[i];
        }
        else {
            timestamps[i] = timestamp;
            hits[i] = 1;
        }


    }

    int getHits(int timestamp) {
        int countHits = 0;

        for (int i = 0; i < NUMBER_SECONDS; ++i) {
            if (timestamp - timestamps[i] < NUMBER_SECONDS) { countHits += hits[i]; }
        }

        return countHits;
    }

private:
    array<int, NUMBER_SECONDS> timestamps;
    array<int, NUMBER_SECONDS> hits;
};

int main(){

    HitCounter foo;
    foo.hit(1); foo.hit(1); foo.hit(1);
    cout << foo.getHits(2);

}
