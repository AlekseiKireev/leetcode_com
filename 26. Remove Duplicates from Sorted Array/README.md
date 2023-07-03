https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Ме Бэ, [7/4/2023 1:46 AM]
Друзья, а зачем в Possible implementation
 (https://en.cppreference.com/w/cpp/algorithm/unique)в

unique (1)
```objectives
template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;
 
    ForwardIt result = first;
    while (++first != last)
        if (!(*result == *first) && ++result != first)
            *result = std::move(*first);
 
    return ++result;
}
```

строка: ++result != first во втором условном операторе?

Ме Бэ, [7/4/2023 1:49 AM]
если что — я закоментировал эту строку и сдал сюда: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ — задача была сдана
