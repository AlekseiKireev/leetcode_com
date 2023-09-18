class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, const int target) {
        
        if(target < matrix.front().front() ||
        matrix.back().back() < target
        ){return false;}

        const int CountColumn = matrix.front().size();
        int LeftBorder = -1;
        int RightBorder = matrix.size() * CountColumn;

        while(2 != RightBorder - LeftBorder + 1){ // RightBorder - LeftBorder + 1 -- количество элементов в отрезке [LeftBorder, RightBorder]

            const int Mid = (RightBorder + LeftBorder) / 2;
            if(matrix[Mid / CountColumn][Mid % CountColumn] < target){
                LeftBorder = Mid;
            } else{ // matrix[Mid / CountColumn][Mid % CountColumn] >= target
                RightBorder = Mid;
            }

        }

        return matrix[RightBorder / CountColumn][RightBorder % CountColumn] == target;

    }
};
