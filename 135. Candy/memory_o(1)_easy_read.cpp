class Solution {
public:
    int candy(vector<int>& ratings) {
        
        const int n = ratings.size();

        int candies = n;

        for(int i = 0; i < n - 1;){ // если оператор тут будет сдигаться -- это ошибка, так как он может сдивагтсья внутри других циклов, не обрабатываться, а потом тут еще раз сдвигаться!        
            
            int Plateau = 0;
            for(; i < n - 1 && ratings[i] == ratings[i + 1]; ++i ){

                candies += Plateau;
                
            }

            int Hight = 0;
            for(;i < n - 1 && ratings[i] < ratings[i + 1]; ++i){
                
                ++Hight;
                candies += Hight;
                
            }

            int Low = 0;
            for(;i < n - 1 && ratings[i] > ratings[i + 1]; ++i){
                
                ++Low;
                candies += Low;
                
            }

            candies -= min(Hight, Low);

        }

        return candies;
    }
};
