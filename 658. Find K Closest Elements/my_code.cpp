class Solution {
public:
    vector<int> findClosestElements(const vector<int>& arr, const int k, const int x) {
        vector<int> ClosestIntegers;

        auto It = lower_bound(arr.begin(), arr.end(), x);

        if(It == arr.begin()){return {arr.begin(), arr.begin() + k};} // My ex 2
        if(It == arr.end()){return {arr.end() - k, arr.end()};} // My ex 3


        // найти индексы и вернуть смещение в arr

        int LeftPtr = ;
        int RightPtr = ;

        return ClosestIntegers;
    }
};
