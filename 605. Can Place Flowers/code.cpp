class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(0 == n){return true;}

        for(int i = 0; i < flowerbed.size(); ++i){

            if(flowerbed[i] == 0){

                bool LeftEmpty = (i == 0 || flowerbed[i-1] == 0);
                bool RightEmpty = (i == flowerbed.size() - 1 || flowerbed[i+1] == 0);

                if(LeftEmpty && RightEmpty){
                    --n;
                    if(0 == n){return true;}
                    flowerbed[i] = 1;
                }
                
            }

        }

        return n == 0;
    }
};
