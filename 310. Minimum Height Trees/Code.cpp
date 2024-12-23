class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) {return {0};}

        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        deque<int> leaves; 
        for (int i = 0; i < n; ++i) {          
            if (graph[i].size() == 1) {leaves.push_back(i);}          
        }

        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            
            int num_leaves = leaves.size();
            remaining_nodes -= num_leaves;

            for (int i = 0; i < num_leaves; ++i) {
                
                int leaf = leaves.front();
                leaves.pop_front();

                int neighbor = *graph[leaf].begin();
                
                graph[neighbor].erase(leaf);
                graph[leaf].clear();

                if (graph[neighbor].size() == 1) {
                    leaves.push_back(neighbor);
                }
            }
        }

        return {leaves.begin(), leaves.end()};
    }
};
