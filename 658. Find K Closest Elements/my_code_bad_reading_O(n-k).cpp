class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        if(arr.size() == k){return arr;}
        auto ItCheck_x = lower_bound(arr.begin(), arr.end(), x);

        if(ItCheck_x == arr.begin()){return {arr.begin(), arr.begin() + k};} // My ex 2 / 2.1
        if(ItCheck_x == arr.end()){return {arr.end() - k, arr.end()};} // My ex 3

        int LeftPtr, RightPtr;
        if(*ItCheck_x == x){
            LeftPtr = RightPtr = ItCheck_x - arr.begin();
        }else{ // *prev(ItCheck_x) < x < *ItCheck_x

            if( abs(*prev(ItCheck_x) - x) == abs(*ItCheck_x - x) ){ 

                LeftPtr = RightPtr = ItCheck_x - arr.begin() - 1; // "-1" <-- [1,3] 1 2

            }else{

                if(abs(*prev(ItCheck_x) - x) < abs(*ItCheck_x - x)){ 
                    LeftPtr = RightPtr = ItCheck_x - arr.begin() - 1; // "-1" <-- [0,0,1,2,3,3,4,7,7,8] 3 5
                }else{
                    LeftPtr = RightPtr = ItCheck_x - arr.begin();
                }

            }

        }
        
        cout << LeftPtr << ' ' << RightPtr << '\n';

        while(k != RightPtr - LeftPtr + 1){

            if( RightPtr == arr.size() - 1 || 
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

            if(LeftPtr == 0){break;}
        }

        cout << LeftPtr << ' ' << RightPtr;


        return {arr.begin() + LeftPtr, arr.begin()  + LeftPtr + k};                        

    }
};
