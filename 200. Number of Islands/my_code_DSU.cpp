class dsu {
    public:
    vector<int> parent;
    vector<int> rank;
    
    dsu(int _n){
        parent.resize(_n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(_n);
    }
    
    int find(int x){
        return (x == parent[x] ? x : parent[x] = find(parent[x]));
    }
    
    void unite(int a, int b){
        a = find(a); b = find(b);
        
        if(a != b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            rank[a]++;
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        
        dsu d(n*m);
        
        
        for(int i = 0; i < n; i++){\
            for(int j = 0; j < m; j++){\
				// connect  current cell with bottom cell if current cell and bottom cell are both '1'
                if(i < n-1 && grid[i][j] == '1' && grid[i + 1][j] == '1') d.unite(i*m + j, (i + 1)*m + j); 
				// connect  current cell with rightward cell if current cell and rightward cell are both '1'
                if(j < m-1 && grid[i][j] == '1' && grid[i][j + 1] == '1') d.unite(i*m + j, i*m + j + 1);
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < (int)d.parent.size(); i++){\
			// iterate over parent arey and look for index that has parent to itself and remove that cells that are '0' and have same parents
            if(i == d.parent[i] && grid[i/m][i%m] != '0') ans++;
        }
        
        return ans;
    }
};
