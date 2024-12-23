class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1) {return {0};}

        // Создаем граф в виде списка смежности
        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        // Находим начальные листья (вершины степени 1)
        deque<int> leaves; // добавлем в конец, т.к. удаляем по листу с начала
        // потом удаляем с начала, новые листья добавляем в конец
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        // Постепенно обрезаем листья
        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            
            int num_leaves = leaves.size();
            remaining_nodes -= num_leaves;

            for (int i = 0; i < num_leaves; ++i) {
                
                int leaf = leaves.front();
                leaves.pop_front();
                // Удаляем лист из графа
                int neighbor = *graph[leaf].begin();
                
                graph[neighbor].erase(leaf);
                graph[leaf].clear();

                // Если сосед стал листом, добавляем его
                if (graph[neighbor].size() == 1) {
                    leaves.push_back(neighbor);
                }
            }
        }

        return {leaves.begin(), leaves.end()};
    }

};
