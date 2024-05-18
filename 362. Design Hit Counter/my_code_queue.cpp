/*
class HitCounter {
 public:
  void hit(int timestamp) {

  }

  int getHits(int timestamp) {

  }

};
*/

#include <iostream>
#include <queue>

using namespace std;

class HitCounter {

private:
    queue<int> Timestamps;

private:

    void clear(const int timestamp) { // "Timestamps.front() + 300 <= timestamp" == условие того, что событие Timestamps.front() произошло ранее 300 секунд при начале отсчета от timestamp
                                     // необходимы события, находящиеся в (timestamp - 300, timestamp]   
        while (Timestamps.empty() == false && Timestamps.front() + 300 <= timestamp) { Timestamps.pop(); } /*"300 <=" -- единственное отличие от 933*/
    }

public:

    void hit(const int timestamp) {
        clear(timestamp);
        Timestamps.push(timestamp);
    }

    int getHits(const int timestamp) {

        /* "and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing)." 
           т.е. при следущюем вызове hit / getHits переданное туда значение будет больше текущего timestamp, ввиду чего вызываем clear
        */
        clear(timestamp); 
        return Timestamps.size();
    }
/*
Для обоих методов, hit и getHits, амортизированная сложность составляет O(1). 
Это обусловлено тем, что каждый элемент добавляется и удаляется из очереди только один раз, что делает среднюю стоимость каждой операции постоянной.
*/
};

int main(){

    HitCounter foo;
    foo.hit(1); foo.hit(1); foo.hit(1);
    cout << foo.getHits(2);

}

/*
Удаление Timestamps.front() происходит при: 
---------|--------------------------------|---------------|
Timestamps.front()                 timestamp - 300    timestamp

В том числе, если Timestamps.front() == timestamp - 300 
*/

/*
int main(){

    HitCounter foo;
    
    foo.hit(1); foo.hit(2); foo.hit(3);
    
    cout << foo.getHits(4) << '\n';
    
    foo.hit(300);
    
    cout << foo.getHits(300) << '\n';
    cout << foo.getHits(301) << '\n';

}
*/
