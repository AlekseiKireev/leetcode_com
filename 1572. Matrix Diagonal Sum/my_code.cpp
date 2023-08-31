class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int SumMatrixDiagonals = 0;

        for(int i = 0; i < mat.size(); ++i){

            SumMatrixDiagonals += mat[i][i]; // главная диагональ
            SumMatrixDiagonals += mat[i][mat.size() - 1 - i]; // побочная диагональ

        }

        /*
"Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal." --> mat[mat.size() / 2][mat.size() / 2] * ((mat.size() % 2))
        */
        return SumMatrixDiagonals - mat[mat.size() / 2][mat.size() / 2] * ((mat.size() % 2));
    }
};
