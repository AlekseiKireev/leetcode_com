class Solution {
public:

// реализация на основе Possible implementation из https://en.cppreference.com/w/cpp/algorithm/unique
template<class ForwardIt>
ForwardIt UNIQUE(ForwardIt first, ForwardIt last) {
    if (first == last) {return last;}
 
    ForwardIt result = first;
    for (;first != last; ++first){
       
        if ((*result != *first) /*&& (++result != first)*/) {
            ++result;
            *result = move(*first);
        }
    }
 
    return ++result;
}

    int removeDuplicates(vector<int>& nums) {

        const auto it = UNIQUE(begin(nums), end(nums));
        return it - begin(nums);
        
    }
};
