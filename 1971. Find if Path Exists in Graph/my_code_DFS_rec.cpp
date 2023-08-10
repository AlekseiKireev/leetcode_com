class Solution {

private:

vector<bool> Visited;

void DFS(const vector<vector<int>>& AdjacencyList, const int source, int destination){
   
    // порядок двух нижележащих строк важен!
    Visited[source] = true;
    if(source == destination){return;}

    for(const int v : AdjacencyList[source]){

        if(Visited[v] == false){DFS(AdjacencyList, v, destination);}

    }

}

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(source == destination){return true;}

        vector<vector<int>> AdjacencyList(n);

        for(const auto edge : edges){

            AdjacencyList[edge.front()].push_back(edge.back());
            AdjacencyList[edge.back()].push_back(edge.front());

        }

        Visited.resize(n);       

        DFS(AdjacencyList, source, destination);

        return (Visited[source] == Visited[destination]);
    }
};
