class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) {return {0};}

        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        deque<int> Leafs; 
        for (int i = 0; i < n; ++i) {          
            if (graph[i].size() == 1) {Leafs.push_back(i);}          
        }

        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            
            int num_Leafs = Leafs.size();
            remaining_nodes -= num_Leafs;

            for (int i = 0; i < num_Leafs; ++i) {
                
                int leaf = Leafs.front();
                Leafs.pop_front();

                int neighbor = *graph[leaf].begin();
                
                graph[neighbor].erase(leaf);
                graph[leaf].clear();

                if (graph[neighbor].size() == 1) {
                    Leafs.push_back(neighbor);
                }
            }
        }

        return {Leafs.begin(), Leafs.end()};
    }
};
