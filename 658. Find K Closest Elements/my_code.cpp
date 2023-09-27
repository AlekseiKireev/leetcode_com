class Solution {
public:
    vector<int> findClosestElements(const vector<int>& arr, int k, const int x) {

        auto It = lower_bound(arr.begin(), arr.end(), x);

        if(It == arr.begin()){return {arr.begin(), arr.begin() + k};} // My ex 2
        if(It == arr.end() || It == prev(arr.end())){return {arr.end() - k, arr.end()};} // My ex 3


        int LeftPtr, RightPtr;

        if(*It == x || abs(*prev(It) - x) >= abs(*It - x)){
            LeftPtr = RightPtr = It - arr.begin();
        }else{
            LeftPtr = RightPtr = It - arr.begin() - 1;
        }

        
        cout << LeftPtr << ' ' << RightPtr << '\n';
        if(k == 1){return {arr.begin() + LeftPtr, arr.begin() + RightPtr + 1};}
        
        while(k != RightPtr - LeftPtr + 1){
        //for(;k != 0;--k){

            if( RightPtr >= arr.size() - 1 || 
                LeftPtr > 0 && 
                (
                abs(arr[LeftPtr - 1] - x) < abs(arr[RightPtr + 1] - x) || 
                abs(arr[LeftPtr - 1] - x) == abs(arr[RightPtr + 1]  - x)
                )
            )
            {
                --LeftPtr;
            }else{
                ++RightPtr;
            }
        }

        cout << LeftPtr << ' ' << RightPtr;


        return {arr.begin() + LeftPtr, arr.begin()  + RightPtr + 1};
    }
};
