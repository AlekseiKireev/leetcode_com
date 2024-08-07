class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0;

        for(int y = 0; y < grid.size(); ++y){

            for(int x = 0; x < grid.front().size(); ++x){

                if(grid[y][x] == 1){

                    perimeter += (0 == y || grid[y-1][x] == 0); // UP
                    perimeter += (y == grid.size() - 1  || grid[y+1][x] == 0); // LOW

                    perimeter += (0 == x || grid[y][x-1] == 0); // LEFT
                    perimeter += (x == grid.front().size() - 1 || grid[y][x+1] == 0); // RIGHT                    
                }
            }

        }

        return perimeter;
    }
};
