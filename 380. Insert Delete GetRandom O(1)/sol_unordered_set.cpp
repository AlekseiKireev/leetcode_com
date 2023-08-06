class RandomizedSet {

    unordered_set<int> values;

public:
    
    bool insert(int val) {
        if (values.find(val) != values.end()) { return false; }
        values.insert(val);
        return true;
    }

    bool remove(int val) {
        if (values.find(val) == values.end()) { return false; }
        values.erase(val);
        return true;
    }

    int getRandom() {
        auto it = values.begin();
        advance(it, rand() % values.size()); // https://en.cppreference.com/w/cpp/numeric/random/rand
        return (*it);
    }
};

/*
Также хочется поделиться идеей: первая мысль была о том, что unordered_set не предоставляет никакого порядка 
(забыл, что рехеширование происходит, вроде, только при операции insert), а если нет порядка, что условный begin возвращает рандомное значение, 
т.е. решение мне виделось так:

class RandomizedSet {

unordered_set<int> values;

public:

bool insert(int val) {
if (values.find(val) != values.end()) { return false; }
values.insert(val);
return true;
}

bool remove(int val) {
if (values.find(val) == values.end()) { return false; }
values.erase(val);
return true;
}

int getRandom() {
auto it = values.begin();
//advance(it, rand() % values.size()); // ТОТ ЖЕ КОД ЧТО В PASTEBIN ВЫШЕ, ЗА ИСКЛЮЧЕНИЕМ ЭТОЙ ЗАКОМЕНЧЕННОЙ СТРОКИ
return (*it);
}
};

Так вот, такое решение проходит первые 17 тестов и падает на входных данных вида:

["RandomizedSet","insert","insert","insert","insert","getRandom","getRandom","getRandom", "getRandom","getRandom","getRandom", ...

думаю, занятное наблюдение, так как, навреное, при собеседовании необходимо писать тесты и мотивировать их
*/
