#include <iostream>
#include <vector>
#include <algorithm>

int maximizeProfit(const std::vector<int>& prices) {
    int n = prices.size();
    int mx = 0, ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        mx = std::max(mx, prices[i]);
        ans += mx;
    }

    return ans;
}

int main() {
    std::vector<int> prices = {1, 3, 1, 2}; // пример входных данных
    int result = maximizeProfit(prices);
    std::cout << "Максимальная прибыль: " << result << std::endl; // Ожидаемый результат: 10

    return 0;
}
