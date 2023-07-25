class Solution {

public:

    int numIslands(vector<vector<char>>& grid) {
        
        if (grid.empty()) {return 0;}
        
        vector<int> q;
        q.reserve(grid.size() * grid[0].size() * 2); // "* 2" обусловлен тем, что в q не как исконно хранятся пары кооринат, а храним пары подряд, т.е. пара имеем вид: {q[2n], q[2n + 1]} : n \in Z_{+}
        
        int qBegin = 0; // изначально - начало очереди, в последствии - позиция в векторе, которую обрабатываем, т.е. указывает на координату в grid, которую надо исследовать
        int ans = 0;
        
        for (int i = 0; i < (int)grid.size(); i++) {
            
            for (int j = 0; j < (int)grid[i].size(); j++) {
                
                if (grid[i][j] == '1') {
                    ans++;
                  
                    q.push_back(i);
                    q.push_back(j);

                    while (qBegin < (int)q.size()) {
                        
                        int i = q[qBegin];
                        qBegin++;
                        int j = q[qBegin];
                        qBegin++;
                        
                        for (int di = -1; di <= 1; di++) {
                            for (int dj = -1; dj <= 1; dj++) {
                                if (di * di + dj * dj == 1) {
                                    int ni = i + di; // == new_i
                                    int nj = j + dj; // == new_j
                                    if (
                                        0 <= ni && ni < (int)grid.size() &&
                                        0 <= nj && nj < (int)grid[ni].size() &&
                                        grid[ni][nj] == '1'
                                        ) {
                                        grid[ni][nj] = '0';
                                        q.push_back(ni);
                                        q.push_back(nj);
                                    }
                                }
                            } // end dj
                            
                        } // end di
                        
                    } // end while
                    
                }
            } // end j
        } // end i
        
        return ans;
    }

};
