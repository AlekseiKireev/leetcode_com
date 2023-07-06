class Solution {
public:

// реализация на основе Possible implementation из https://en.cppreference.com/w/cpp/algorithm/unique
template<class ForwardIt>
ForwardIt UNIQUE(ForwardIt first, ForwardIt last) {
    
    if (first == last) {return last;} // check for empty nums
 
    ForwardIt result = first; // result в конечном итоге должен указывать на такой итератор, что слева от result лежат все уникальные значения из {first, ..., prev(last)}
    for (;first != last; ++first){ // first = prev(end(nums)) -- extreme values for first
       
        if ((*result != *first)) {
            ++result;
            *result = move(*first);
        }
    }
 
    return ++result; // если не инкременитровать result, то он будет указывать на последний [максимальный] уникальный элемент из {first, ..., prev(last)}, что противоречит определению
}

    int removeDuplicates(vector<int>& nums) {

        const auto it = UNIQUE(begin(nums), end(nums));
        return it - begin(nums);
        
    }
};
