class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        while(!coins.empty() && amount < coins.back()){
            coins.pop_back();
        }
        vector<int> DP(amount + 1, amount + 1); // idx --> val == SumCoins --> FewestNum
        DP[0] = 0; // база DP

        for(int coin : coins){
            for(int SumCoins = coin; SumCoins <= amount; ++SumCoins){ // смотрим как можно сформировать иные суммы с монетой coin. Если нельзя, то DP[SumCoins] = amount + 1
                DP[SumCoins] = min(DP[SumCoins], DP[SumCoins - coin] + 1);
            }            
        }

        return (DP.back() == amount + 1 ? -1 : DP.back());

    }
};
