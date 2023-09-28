 int closer;

class Solution {

/* // error!
private:

 int closer;
static  int closer;
*/

private:

// error: reference to non-static member function must be called sort(arr.begin(), arr.end(), Comp);
static bool Comp(const int a, const int b) {

    const int Buffer = abs(a - closer) - abs(b - closer);
    return (Buffer == 0 ? a < b : Buffer < 0);
}

public:
    vector<int> findClosestElements(vector<int>& arr, const int k, const int x) {
        
        closer = x;
        sort(arr.begin(), arr.end(), Comp);
        
        sort(arr.begin(), arr.begin() + k); // "The result should also be sorted in ascending order."
        return {arr.begin(), arr.begin() + k};
    }
};
