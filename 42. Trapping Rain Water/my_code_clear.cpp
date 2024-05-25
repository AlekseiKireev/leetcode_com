class Solution {
public:
    int trap(vector<int>& height) {
        
        auto it = ranges::max_element(height);

        int IdxMaxHeight = it - height.begin();

        int TotalSum = 0;

        int LocalMaxHeight = 0;

        for(int i = 0; i < IdxMaxHeight; ++i){
            
            LocalMaxHeight = max(LocalMaxHeight, height[i]);
            TotalSum += (LocalMaxHeight - height[i]);
        }

        LocalMaxHeight = 0;
        for(int i = height.size() - 1; i > IdxMaxHeight; --i){
            
            LocalMaxHeight = max(LocalMaxHeight, height[i]);
            TotalSum += (LocalMaxHeight - height[i]);
        }        

        return TotalSum;
    }
};
