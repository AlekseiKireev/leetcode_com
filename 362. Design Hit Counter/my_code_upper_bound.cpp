#include <iostream>
#include <vector>

using namespace std;

class HitCounter {

private:
    vector<int> Timestamps;

public:

    HitCounter() {
        Timestamps.reserve(300);
        
    }
    
    void hit(const int timestamp) {
        Timestamps.push_back(timestamp);
    }

    int getHits(const int timestamp) {

        
        return Timestamps.end() - upper_bound(Timestamps.begin(), Timestamps.end(), timestamp - 300);
    }

};

int main(){

    HitCounter foo;
    
    foo.hit(1); foo.hit(2); foo.hit(3);
    
    cout << foo.getHits(4) << '\n';
    
    foo.hit(300);
    
    cout << foo.getHits(300) << '\n';
    cout << foo.getHits(301) << '\n';

}
