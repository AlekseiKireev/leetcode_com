#include <bits/stdc++.h>
using namespace std;

class DataStream {
private:
    list<int> UniqieList;
    unordered_map<int, list<int>::iterator> NumToItr;// необходим для быстрого удаления из UniqieList в случае, если num уже существует в NumToItr

public:
    DataStream() {}

    void add(int num) {
        // TC: O(1)
        if (NumToItr.count(num)) {
            
            if (NumToItr[num] == UniqieList.end()) {// встретили num более 2 раз, гарантировано не ниукальынй
                return;
            }

            // встретили num 2 раз: теперь он гарантировано не уникальный, удаляем его и ставим на него метку UniqieList.end() в NumToItr -- чтобы знать, что встречался 2 раза, т.е. элдемент не уникальный 
            auto item = NumToItr[num];
            UniqieList.erase(item);
            NumToItr[num] = UniqieList.end();
          
        } else { // встретили num 1 раз: добавили элемент
          
            UniqieList.push_back(num);
            NumToItr[num] = prev(UniqieList.end());
          
        }
    }


    int firstUnique() { // возвращаем самый ранний элемент
        // TC: O(1)
        if (UniqieList.empty()) {
            throw runtime_error("No unique numbers available");
        }
        return (*UniqieList.begin());
    }
};

int main() {
    DataStream ds;
    ds.add(1);
    ds.add(2);
    ds.add(1);
    cout << ds.firstUnique() << endl;  // Output: 2
    ds.add(2);
    try {
        cout << ds.firstUnique() << endl;  // Should throw an exception
    } catch (const runtime_error& e) {
        cout << e.what() << endl;  // Output: No unique numbers available
    }
    ds.add(3);
    cout << ds.firstUnique() << endl;  // Output: 3
    return 0;
}
