class DSU{

private:

vector<int> RankSize;
vector<int> Parent;

int StartingNumberLeaders;

public:

    DSU(int StartingNumberLeaders_) : StartingNumberLeaders(StartingNumberLeaders_){

        RankSize.resize(StartingNumberLeaders, 1);
        Parent.resize(StartingNumberLeaders);

        for(int i = 0; i < StartingNumberLeaders; ++i){
            Parent[i] = i;
        }

    }

    int Find(int Parent){

        return (Parent[Parent] == Parent) ? Parent : Parent[Parent] = Find(Parent[Parent]);

    }

    void Union(int Parent_1, int Parent_2){

        
        int Leader_1 = Find(Parent_1);
        int Leader_2 = Find(Parent_2);

        if(Leader_1 == Leader_2){return;}

        if(RankSize[Leader_1] < RankSize[Leader_2]){
            swap(Leader_1, Leader_2);
        }

        assert(RankSize[Leader_2] <= RankSize[Leader_1]); // подвешиваем дерево с мЕньшим рангом за дерево с бОльшим рангом

        Parent[Leader_2] = Leader_1;
        RankSize[Leader_1] += RankSize[Leader_2];
        RankSize[Leader_2] = 0;
        
    }

};

class Solution {

private:

    int NumberRows;
    int NumberColumns;

    int CoordToNumber(int row, int column){
        return row * NumberColumns + column;
    }

public:

    int numIslands(const vector<vector<char>>& grid) {
        
        if(grid.empty()){return 0;}

        NumberRows = grid.size();
        NumberColumns = grid.back().size();

        DSU dsu(NumberRows * NumberColumns);

        // Будем сливать 
        for(int y = 0; y < NumberRows;++y){ // == номер строки
            for(int x = 0; x < NumberColumns;++x){ // == номер столбца
                                
                if(x != 0 && grid[y][x] == '1' && grid[y][x-1] == '1' ){
                    
                    dsu.Union(CoordToNumber(y,x), CoordToNumber(y,x - 1));
                }
                if(y != 0 && grid[y][x] == '1' && grid[y-1][x] == '1' ){
                    
                    dsu.Union(CoordToNumber(y,x), CoordToNumber(y - 1,x ));
                }
              
            }
        }

        unordered_set<int> SetLeaders;

        for(int y = 0; y < NumberRows;++y){ // == номер строки
            for(int x = 0; x < NumberColumns;++x){ // == номер столбца
                if(grid[y][x] == '1'){SetLeaders.insert(dsu.Find(CoordToNumber(y,x)));}
            }
        }

        return SetLeaders.size();

    }

};
