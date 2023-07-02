class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<pair<int, int>> Idx_To_HeightVal;

      // осталось реализовать обход дерева, в ходе которого заполяем Idx_To_HeightVal


        vector<vector<int>> ValuesOnHeight; 
      ValuesOnHeight.reserve(Idx_To_HeightVal.size()); // резервируем данные в указанном количемтве на случай, если дерево обратится в бамбук
        for(auto [Height, Val] : Idx_To_HeightVal){

            ValuesOnHeight[Height].push_back(Val);
        }

        ValuesOnHeight.shrink_to_fit(); // освобождаем данные, занятые capacity
        return ValuesOnHeight;
    }
};
