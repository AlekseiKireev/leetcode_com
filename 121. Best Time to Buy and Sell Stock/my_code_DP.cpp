class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        const int N = prices.size();
        vector<int> maxPrices(N);

        maxPrices.back() = prices.back();

        for(int i = N - 2; i >= 0; --i){

            maxPrices[i] = max(maxPrices[i + 1], prices[i]);
            
        }

        int MaximumProfit = 0;

        for(int i = 0; i < N; ++i){

            MaximumProfit = max(MaximumProfit,maxPrices[i] - prices[i]);

        }

        return MaximumProfit;

    }
};
