/*
class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {

  }

  int next() {

  }

  bool hasNext() {
    
  }
};
*/

#include <iostream>
#include <queue>

using namespace std;


class ZigzagIterator {

private:

    struct Pair {
        vector<int>::const_iterator CurrentItr;
        vector<int>::const_iterator EndItr;
    };

private:

    queue<Pair> GetZigzag;

public:
    ZigzagIterator(const vector<int>& v1, const vector<int>& v2) { // 0 <= v1.length, v2.length <= 1000        

        
        if (v1.empty() == false) { GetZigzag.push({ v1.cbegin(), v1.cend() }); }
        if (v2.empty() == false) { GetZigzag.push({ v2.cbegin(), v2.cend() }); }
        //if (v1.empty() == false) { GetZigzag.emplace( v1.cbegin(), v1.cend() ); }
        //if (v2.empty() == false) { GetZigzag.emplace( v2.cbegin(), v2.cend() ); }

    }

    int next() {


        const auto [CurrentItr, EndItr] = GetZigzag.front();
        GetZigzag.pop();
        if (CurrentItr + 1 != EndItr) { GetZigzag.push({ CurrentItr + 1, EndItr }); }
        return *CurrentItr;
    }

    bool hasNext() { return !(GetZigzag.empty()); }

};


int main() {

    vector<int> v1 = { 1,2 };
    vector<int> v2 = { 3,4,5,6 };
    auto Tmp = ZigzagIterator(v1, v2);

    while (Tmp.hasNext()) {
        cout << Tmp.next() << ' ';
    }

}
       
/*

вопрос: почему конструкция в ZigzagIterator

        if (v1.empty() == false) { GetZigzag.push({ v1.cbegin(), v1.cend() }); }
        if (v2.empty() == false) { GetZigzag.push({ v2.cbegin(), v2.cend() }); }

является ошибочной:
no instance of overloaded function "std::queue<_Ty, _Container>::push [with _Ty=ZigzagIterator::Pair, _Container=std::deque<ZigzagIterator::Pair, std::allocator<ZigzagIterator::Pair>>]" matches the argument list
в то время как

        if (v1.empty() == false) { GetZigzag.emplace( v1.cbegin(), v1.cend() ); }
        if (v2.empty() == false) { GetZigzag.emplace( v2.cbegin(), v2.cend() ); }

верной? Если не ошибаюсь, первая версия тоже должна работать...
К слову, в 39 строке все работает...


UPD

Если избавиться от константности

    ZigzagIterator( vector<int>& v1,  vector<int>& v2) { // 0 <= v1.length, v2.length <= 1000

        if (v1.empty() == false) { GetZigzag.push({ v1.begin(), v1.end() }); }
        if (v2.empty() == false) { GetZigzag.push({ v2.begin(), v2.end() }); }

    }

все работает... почему так?



Mikhail, [10/3/2023 10:19 PM]
Итераторы в структуре Pair должны быть константными:

struct Pair {
    vector<int>::const_iterator CurrentItr;
    vector<int>::const_iterator EndItr;
};

То есть так: 

    struct Pair {

        const vector<int>::iterator CurrentItr;
        const vector<int>::iterator EndItr;

    };

ошибочно...    

F L, [10/3/2023 10:20 PM]
а emplace почему это попустил? emplace и при такой конструкции работает...
* Просто поделился, занятно

Mikhail, [10/3/2023 10:33 PM]
хм, а какой компилятор?

F L, [10/3/2023 10:34 PM]
MVS

Mikhail, [10/3/2023 10:35 PM]
на gcc 13.2 не срабатывает
*/
