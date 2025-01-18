class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int candies = ratings.size();

        for(int i = 1; i < ratings.size();){
          
            for(;i < ratings.size() && ratings[i] == ratings[i-1];++i);

          
            int Hight = 0;
            int Low = 0;            

            for(;i < ratings.size() && ratings[i] > ratings[i-1];++i){
                ++Hight;
                candies += Hight;
            }

            for(;i < ratings.size() && ratings[i] < ratings[i-1];++i){
                ++Low;
                candies += Low;
            }

            candies -=min(Hight, Low);
        }

        return candies;
    }
};
