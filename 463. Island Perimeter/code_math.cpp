class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int neighbors = 0; // так как идем сверху-вниз слева-направа, то сверху соседей быть не может, как и слева
        int lands  = 0;
        for(int y = 0; y < grid.size(); ++y){

            for(int x = 0; x < grid.front().size(); ++x){

                if(grid[y][x] == 1){

                    ++lands;

                    // neighbor right
                    if(x+1 < grid.front().size() && grid[y][x+1] == 1){++neighbors;}

                    // neighbor down
                    if(y+1 < grid.size() && grid[y+1][x] == 1){++neighbors;}

                }
            }

        }

        return lands*4 - neighbors*2; // lands*4 -- площадь каждого участка суши; neighbors*2 -- так как в lands*4 подсчитывались соседи дважды (при наличии соседей), то вычитаем умноженное на 2
    }
};
