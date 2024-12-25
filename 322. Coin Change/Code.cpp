class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        

        vector<int> DP(amount + 1, amount + 1); // idx --> val == SumCoins --> FewestNum
        DP[0] = 0; // база DP

        for(int coin : coins){
            for(int SumCoins = coin; SumCoins < amount + 1; ++SumCoins){
                DP[SumCoins] = min(DP[SumCoins], DP[SumCoins - coin] + 1);
            }            
        }

        return (DP.back() == amount + 1 ? -1 : DP.back());

    }
};
