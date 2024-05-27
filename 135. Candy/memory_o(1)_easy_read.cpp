class Solution {
public:
    int candy(vector<int>& ratings) {
        
        const int n = ratings.size();

        int candies = n;

        // если i в какой-то момент = n - 1, то не сможем сдвинуть в внутренних циклах i --> бесконечный цикл!
        for(int i = 0; i < n - 1;){ // если оператор тут будет сдигаться -- это ошибка, так как он может сдивагтсья внутри других циклов, не обрабатываться, а потом тут еще раз сдвигаться!        
            
            int Plateau = 0;
            for(; i < n - 1 && ratings[i] == ratings[i + 1]; ++i ){

                candies += Plateau;
                
            }

            int Hight = 0;
            // перед заходом в цикл вес ratings[i]  равен 1, это видно из графика!
            for(;i < n - 1 && ratings[i] < ratings[i + 1]; ++i){ 
                
                ++Hight;
                // за ratings[i + 1] закрепляем вес Hight+1 (но +1 учли в инициаллизации candies, поэтому не пишем!)
                candies += Hight;
                
            }

            int Low = 0;
            // перед заходом в цикл вес ratings[i]  равен 1, это видно из графика!
            for(;i < n - 1 && ratings[i] > ratings[i + 1]; ++i){
                
                ++Low;
                // за ratings[i + 1] закрепляем вес Low+1 (но +1 учли в инициаллизации candies, поэтому не пишем!)
                candies += Low;
                
            }

            candies -= min(Hight, Low);

        }

        return candies;
    }
};
