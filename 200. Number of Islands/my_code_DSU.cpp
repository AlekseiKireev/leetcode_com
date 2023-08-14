#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <cassert>

using namespace std;

class DSU {

private:

    vector<int> Rank;
    vector<int> Parent; // "для каждого элемента мы храним номер его предка в дереве"
    int StartingNumberLeaders;


public:

    DSU(const int StartingNumberLeaders) : StartingNumberLeaders(StartingNumberLeaders) {

        Parent.resize(StartingNumberLeaders + 1);
        Rank.resize(StartingNumberLeaders + 1, 0);

        for (int i = 0; i <= StartingNumberLeaders; ++i) { 
            Parent[i] = i; 
        }

    }


    void Union(int U, int V) {

        int LeaderU = Find(U);
        int LeaderV = Find(V);
        if (LeaderU == LeaderV) { return; }

        if (Rank[LeaderU] < Rank[LeaderV]) { swap(LeaderU, LeaderV); }

        assert(Rank[LeaderV] <= Rank[LeaderU]); // За бОльшее по высоте дерево подвешиваем мАлое

        Parent[LeaderU] = LeaderV;

        if (Rank[LeaderU] == Rank[LeaderV]) { ++Rank[LeaderU]; }

    }



    int Find(const int x) {

        int Leader = x;

        while (Parent[Leader] != Leader) {
            Leader = Parent[Leader];
        }

        int i = x;
        while (Parent[i] != i) {
            int j = Parent[i];
            Parent[i] = Leader;
            i = j;
        }

        return Leader;

    }

};


class Solution {

private:

    int NumberRows;
    int NumberColumns;
    
    // Тут: https://github.com/SkosMartren/leetcode_com/tree/main/470.%20Implement%20Rand10()%20Using%20Rand7() можно заметить аналогичный подход.
    // Оттуда же хорошо видно, что данная функция занимается биекцией двумерных координат, состоящих из натуральных чисел, в натрунатуральное число
    int CoordToSeqNumb(int IdxRow, int IdxColumn) { return (IdxRow - 1) * NumberColumns + IdxColumn; } // coordinate to sequence number
    /* int NonNegativeCoordToSeqNumb(int IdxRow, int IdxColumn) { return (IdxRow) * NumberColumns + IdxColumn; }*/
public:

    int numIslands(vector<vector<char>>& grid) {

        NumberRows = grid.size();
        NumberColumns = grid[0].size();

        DSU dsu(NumberRows * NumberColumns);

        for (int i = 0; i < NumberRows; ++i) { // y == строка
            for (int j = 0; j < NumberColumns; ++j) { // x == столбец

                if (grid[i][j] == '1') {

                    if (j && grid[i][j] == grid[i][j - 1]) { dsu.Union(CoordToSeqNumb(i + 1, j + 1), CoordToSeqNumb(i + 1, j)); }
                    if (i && grid[i][j] == grid[i - 1][j]) { dsu.Union(CoordToSeqNumb(i + 1, j + 1), CoordToSeqNumb(i, j + 1)); }
                    /*
                    if (j && grid[i][j] == grid[i][j - 1]) { dsu.Union(NonNegativeCoordToSeqNumb(i, j), NonNegativeCoordToSeqNumb(i , j - 1)); }
                    if (i && grid[i][j] == grid[i - 1][j]) { dsu.Union(NonNegativeCoordToSeqNumb(i, j), NonNegativeCoordToSeqNumb(i - 1, j)); }
                    */

                }
            }
        }

        unordered_set<int> SetLeaders;

        for (int i = 0; i < NumberRows; ++i) {
            for (int j = 0; j < NumberColumns; ++j) {
                if (grid[i][j] == '1') SetLeaders.insert(dsu.Find(CoordToSeqNumb(i + 1, j + 1)));
                /*if (grid[i][j] == '1') SetLeaders.insert(dsu.Find(NonNegativeCoordToSeqNumb(i, j)));*/
            }

        }

        return int(SetLeaders.size());
    }

};
