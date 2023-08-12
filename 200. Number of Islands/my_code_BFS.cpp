class Solution {

struct Pair{

int x;
int y;

};

void BFS(vector<vector<char>>& grid, int i, int j) {

    queue<Pair> BurningVertexes; // Queue -- содержит вершины из текущего кольца огня и, может быть, последующего 
    
    grid[i][j] = '0'; // обозначаем вершину посещенной 
    BurningVertexes.push({ i, j });

    while (BurningVertexes.empty() == false) {

        const int x = BurningVertexes.front().x;
        const int y = BurningVertexes.front().y;

        BurningVertexes.pop();

        for (const auto [dx, dy] : vector<pair<int, int>>{ {0, 1},{1, 0},{0, -1},{-1, 0} }) { // or: array<int, 5> Step = { 0,1,0,-1,0 };

            /* проверка индексов на валидность: ввиду смещения они могут выйти за границу двумерного массива:
              * слева или сверху, т.е. x + dx или y + dy будет меньше нуля соответственно
              * справа, т.е. x + dx >= grid.size(), где grid.size() число строк
              * снизу, т.е. y + dy >= grid.back().size(), где grid.back().size() число столбцов
            */
            if (
                0 <= x + dx && x + dx < grid.size()
                &&
                0 <= y + dy && y + dy < grid.front().size()
                &&
                grid[x + dx][y + dy] == '1'
               ) 
                {

                    grid[x + dx][y + dy] = '0';  // обозначаем вершину посещенной 
                    BurningVertexes.push({ x + dx, y + dy });

                }

        }

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
                    BFS(grid, i, j);
                }
            }
        }

        return NumberIslands;
    }
};

