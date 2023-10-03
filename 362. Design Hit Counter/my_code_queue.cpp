/*
class HitCounter {
 public:
  void hit(int timestamp) {

  }

  int getHits(int timestamp) {

  }

};
*/

class HitCounter {

private:
queue<int> Timestamps;

private:

    void clear(const int timestamp){
        while(Timestamps.empty() == false && Timestamps.front() + 300 <= timestamp){Timestamps.pop()}
    }

public:

    void hit(const int timestamp) {
        clear(timestamp);
        Timestamps.push(timestamp);
    }

    int getHits(const int timestamp) {
        clear(timestamp);
        return Timestamps.size();
    }

};
