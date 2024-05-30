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
