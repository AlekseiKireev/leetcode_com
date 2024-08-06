class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int Sell = 0;
        int Buy = 0;
        int Total = 0;

        for(int i = 0; i  < prices.size(); ){ // объяснить!

            for(; i + 1 < prices.size() && prices[i] >= prices[i+1]; ++i);
            
            Buy = prices[i];

            for(; i + 1 < prices.size() && prices[i] < prices[i+1]; ++i);
            Sell = prices[i];

            Total += Sell - Buy;
            if(i  == prices.size() - 1){break;}
        }

        return Total;
        
    }
};
