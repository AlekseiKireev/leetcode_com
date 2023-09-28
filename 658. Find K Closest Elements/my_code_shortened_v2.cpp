class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        auto ItCheck_x = lower_bound(arr.begin(), arr.end(), x);

        if(ItCheck_x == arr.begin()){return {arr.begin(), arr.begin() + k};} // My ex 2 / 2.1
        if(ItCheck_x == arr.end()){return {arr.end() - k, arr.end()};} // My ex 3

        assert(ItCheck_x != arr.begin() && ItCheck_x != arr.end()); // <--> prev(ItCheck_x) exist!
        assert(*arr.begin() <= x && x <= *prev(arr.end()));
        
        int LeftPtr, RightPtr;      

        bool NearestClosest =  ( abs(*prev(ItCheck_x) - x) == abs(*ItCheck_x - x) || abs(*prev(ItCheck_x) - x) < abs(*ItCheck_x - x));

        LeftPtr = RightPtr = ItCheck_x - arr.begin() - NearestClosest; 


        while(k != RightPtr - LeftPtr + 1){

            if( RightPtr == arr.size() - 1 || 
                (LeftPtr > 0 && 
                (
                abs(arr[LeftPtr - 1] - x) < abs(arr[RightPtr + 1] - x) || 
                abs(arr[LeftPtr - 1] - x) == abs(arr[RightPtr + 1]  - x)
                ))
            )
            {
                --LeftPtr;
                if(LeftPtr == 0){break;}
            }else{
                ++RightPtr;
            }
           
        }


        return {arr.begin() + LeftPtr, arr.begin()  + LeftPtr + k};                        

    }
};
