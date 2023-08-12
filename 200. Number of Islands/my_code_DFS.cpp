class Solution {

                /*

                * == точка интереса, надо посетить и узнать, есть ли там суша

                .*.
                *1*
                .*.

                Поэтому передаем в DFS координаты

                */
                
void DFS(vector<vector<char>>& grid, int i, int j){

    // if(grid[i][j] != '1'){return;} // можно написать такой условный оператор, вмесо "if(grid[i + dx][j + dy] != '1'){continue;}"
    grid[i][j] = '2'; // '2' == visited

    for(auto [dx, dy] : vector<pair<int, int>>{{0,1}, {0,-1}, {1,0}, {-1,0} }){

        /* проверка индексов на валидность: ввиду смещения они могут выйти за границу двумерного массива:
          * слева или сверху, т.е. i + dx или j + dy будет меньше нуля соответственно
          * справа, т.е. i + dx >= grid.size(), где grid.size() число строк
          * снизу, т.е. j + dy >= grid.back().size(), где grid.back().size() число столбцов
        */
        if((i + dx) * (j + dy) < 0 || (i + dx) >= grid.size() || (j + dy) >= grid.back().size()){continue;}
        if(grid[i + dx][j + dy] != '1'){continue;}

        DFS(grid, i + dx, j + dy);

    }

}

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int NumberIslands = 0;

        if(grid.empty()){return NumberIslands;}

        for(int i = 0; i  < grid.size(); ++i){ // обход по стркоам
            for(int j = 0; j < grid.back().size(); ++j){ // обход по столбцам
                
                if(grid[i][j] == '1'){
                    ++NumberIslands;
                    DFS(grid, i, j);
                }
            }
        }

        return NumberIslands;
    }
};
