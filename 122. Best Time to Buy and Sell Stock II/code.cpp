class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int Total = 0;

        for(int i = 0; i + 1 < prices.size(); ){ 

            int Sell = 0;
            int Buy = 0;

            for(; i + 1 < prices.size() && prices[i] >= prices[i+1]; ++i);            
            Buy = prices[i];

            for(; i + 1 < prices.size() && prices[i] < prices[i+1]; ++i);
            Sell = prices[i];

            Total += Sell - Buy;

        }

        return Total;
        
    }
};
