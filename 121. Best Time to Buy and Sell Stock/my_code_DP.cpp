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
/* по объяснению ФМ:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int MAX_Profit = 0;
        int PostfixMaxSell = -1;

        for(int i = prices.size() - 2; i >= 0; --i){
            PostfixMaxSell = max(PostfixMaxSell, prices[i+1]);
            MAX_Profit = max(MAX_Profit, PostfixMaxSell - prices[i]);
        }

        return MAX_Profit;
    }
};
*/
