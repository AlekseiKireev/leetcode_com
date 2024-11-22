/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int maxArea(const vector<int>& height) {
        
        // "maximum amount of water a container can store" == (RightPtr - LeftPtr) * min(height[RightPtr], height[LeftPtr])
        // <= max(height) * max(height.size()) <= 10 ^ 9 <-- 0 <= height[i] <= 10^4 | 2 <= height.length <= 10^5
        
        // "min(height[RightPtr], height[LeftPtr])" обусловлен тем, что вода может вытекать <--> уровень воды не может быть выше
        // высоты минимального ограничения

        int RightPtr = height.size() - 1;
        int LeftPtr = 0;

        int Ans = 0; // <-- "0 <= height[i] <= 10^4" -- т.е. при 0 = height[i] для любого i --> исксомое равно 0

        while(RightPtr != LeftPtr){

            assert(LeftPtr <= RightPtr); 
            Ans = max( Ans, (RightPtr - LeftPtr) * min(height[RightPtr], height[LeftPtr]) ); // algorithm max <-- "!!!maximum!!! amount of water a container can store."

            (height[RightPtr] < height[LeftPtr]) ? --RightPtr: ++LeftPtr;

        }


        return Ans;
    }
};
