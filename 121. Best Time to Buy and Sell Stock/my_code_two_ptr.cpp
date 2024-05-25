/*
s == RightPtr 
b == LeftPtr 

Только работаем не с указателями, а сразу с значениями, на которые они указывают
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int MaximumProfit = 0; // == max{prices[s] - prices[b] : 0 <= b < s <= prices.size() - 1}

        // if(prices.empty()){return MaximumProfit;} // 1 <= prices.length <= 10^5

        int MinPrice = prices.front();// == prices[b]

        // "i = 1" --> b < s && int MinPrice = prices.front();// == prices[b]
        for(int i = 1; i < prices.size(); ++i){ // prices[i] == prices[s] 

            //MinPrice = min(MinPrice, prices[i]);

            // Обрабатывается убывающая последовательность стоимостей: при падении стоимости продавать смысла нет, при этом есть смысл найти наиболее минимальную стоимость, чтобы купить акцию по самой дешевой цене
            while(MinPrice >= prices[i] && i < prices.size() - 1){ // prices = [..., 7,6,5,4,4,4...]
                
                MinPrice = prices[i];
                ++i;
            } // prices[i] > MinPrice

            MaximumProfit = max(MaximumProfit, prices[i] - MinPrice);

        }

        return MaximumProfit;
    }
};
/*
Идея в том, что стоимость с теченим времени либо возрастает, либо не изменяется, либо убывает. Если убывает или не изменяется, надо купить по минимальной цене. 
Продавать пока стоимостьь возрастает и продать в момент локального максимума стоимости
*/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int MaximumProfit = 0; // == max{prices[s] - prices[b] : 0 <= b < s <= prices.size() - 1}

        // if(prices.empty()){return MaximumProfit;} // 1 <= prices.length <= 10^5

        int MinPrice = prices.front();// == prices[b]

        for(int i = 0; i < prices.size(); ++i){ // prices[i] == prices[s] 

            MinPrice = min(MinPrice, prices[i]);
            MaximumProfit = max(MaximumProfit, prices[i] - MinPrice);

        }

        return MaximumProfit;
    }
};
*/
