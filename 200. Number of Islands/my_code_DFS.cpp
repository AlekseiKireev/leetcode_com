class Solution {

                /*

                * == точка интереса, надо посетить и узнать, есть ли там суша

                .*.
                *1*
                .*.

                Поэтому передаем в DFS координаты

                */
                
void DFS(vector<vector<char>>& grid, int i, int j){

    grid[i][j] = '2'; // '2' == visited

    for(auto [dx, dy] : vector<pair<int, int>>{{0,1}, {0,-1}, {1,0}, {-1,0} }){

        /* проверка индексов на валидность: ввиду смещения они могут выйти за границу двумерного массива:
          * слева или сверху, т.е. i + dx или j + dy будет меньше нуля соответственно
          * справа, т.е. i + dx >= grid.size(), где grid.size() число строк
          * снизу, т.е. j + dy >= grid.back().size(), где grid.back().size() число столбцов
        */
        if((i + dx) * (j + dy) < 0 || (i + dx) >= grid.size() || (j + dy) >= grid.back().size()){continue;}
        
        // Вершина с координатами (i,j) не посещена, надо в нее зайти и обозначить как visited, также проверить ее соседей на grid[i + dx][j + dy] == '1'
        if(grid[i + dx][j + dy] == '1'){DFS(grid, i + dx, j + dy);}

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


/*
class Solution {

 const array<pair<int, int>, 4> dt = {{{0,1}, {1,0}, {-1,0}, {0,-1}}}; // обрати внимание на скобки!

void DFS(int y, int x, vector<vector<char>>& grid){

    grid[y][x] = '0'; // visited

    for(auto [dx, dy] : dt){

        if(
            0 <= y + dy && y + dy < grid.size() // проверка выхода за границу
            &&
            0 <= x + dx && x + dx < grid.back().size() // проверка выхода за границу
            &&
            grid[y + dy][x + dx] =='1' // условие вызова DFS для отметки visited
        ){
            DFS(y + dy, x + dx, grid);
        }

    }
}

public:
    int numIslands(vector<vector<char>>& grid) {
        
        int Component  = 0;
        for(int y = 0; y < grid.size(); ++y){
            for(int x  =0; x < grid.back().size(); ++x){

                if(grid[y][x] - '0' == 1){
                    ++Component ;
                    DFS(y,x,grid);
                }

            }            
        }

        return Component;

    }
};
*/
