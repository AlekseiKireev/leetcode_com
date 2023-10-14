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

    void clear(const int timestamp){ // "Timestamps.front() + 300 <= timestamp" == условие того, что событие Timestamps.front() произошло ранее 300 секунд при начале отсчета от timestamp
                                     // необходимы события, находящиеся в (timestamp - 300, timestamp]   
     while(Timestamps.empty() == false && Timestamps.front() + 300 <= timestamp){Timestamps.pop();}
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

/*
Удаление Timestamps.front() происходит при: 
---------|--------------------------------|---------------|
Timestamps.front()                 timestamp - 300    timestamp

В том числе, если Timestamps.front() == timestamp - 300 
*/
