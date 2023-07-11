class Solution {

const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
    
}();

public:
    int search(vector<int>& a, int target) {
    
    auto it = lower_bound(a.begin(), a.end(), target); 

    if (it == a.end())  {return -1; }
    else 
    if (*it > target) {return -1; }
    else  
    return (int)(it - a.begin()); 

    }
};


