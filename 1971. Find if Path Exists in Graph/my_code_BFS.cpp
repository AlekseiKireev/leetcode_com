class Solution {

private:

bool BFS(const int n, const vector<vector<int>>& AdjacencyList, const int source, const int destination){

    vector<bool> Visited(n, false);
    queue<int> BurningVertexes; 
    BurningVertexes.push(source);
    Visited[source] = true;

    while(BurningVertexes.empty() == false){

        int Vertex = BurningVertexes.front(); BurningVertexes.pop();
        if(Vertex == destination){return true;}

        for(const int v : AdjacencyList[Vertex]){
            
            if(Visited[v] == false){
                if(v == destination){return true;}
                BurningVertexes.push(v);
                Visited[v] = true;
            }
        }

    }

    return false;
}

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> AdjacencyList(n);

        for(const auto edge : edges){

            AdjacencyList[edge.front()].push_back(edge.back());
            AdjacencyList[edge.back()].push_back(edge.front());

        }

        return BFS(n, AdjacencyList, source, destination);

    }
};
