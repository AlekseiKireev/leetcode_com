class Solution {
public:
    int trap(vector<int>& height) {
        
        auto it = ranges::max_element(height);

        int IdxMaxHeight = it - height.begin(); // ищем глобальный максимум чтобы гарантировать, что через него не переливается вода

        int TotalSum = 0;

        int LocalMaxHeight = 0;

        for(int i = 0; i < IdxMaxHeight; ++i){
            
            LocalMaxHeight = max(LocalMaxHeight, height[i]); // IdxMaxHeight -- локальный максимум слева, IdxMaxHeight -- глобальный максимум справа, теперь вода может перелиться разве что через локальный максимум
            TotalSum += (LocalMaxHeight - height[i]);
        }

        LocalMaxHeight = 0;
        for(int i = height.size() - 1; i > IdxMaxHeight; --i){
            
            LocalMaxHeight = max(LocalMaxHeight, height[i]); // IdxMaxHeight -- локальный максимум справа, IdxMaxHeight -- глобальный максимум слева, теперь вода может перелиться разве что через локальный максимум
            TotalSum += (LocalMaxHeight - height[i]);
        }        

        return TotalSum;
    }
};
