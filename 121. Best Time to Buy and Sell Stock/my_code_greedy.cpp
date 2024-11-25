/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int MaximumProfit = 0; // == max{prices[s] - prices[b] : 0 <= b < s <= prices.size() - 1}

        // if(prices.empty()){return MaximumProfit;} // 1 <= prices.length <= 10^5

        int MinPrice = prices.front();// == prices[b] -- или можно взять локальный максимум

        for(int i = 0; i < prices.size(); ++i){ // prices[i] == prices[s] 

            MinPrice = min(MinPrice, prices[i]);
            MaximumProfit = max(MaximumProfit, prices[i] - MinPrice);

        }

        return MaximumProfit;
    }
};
