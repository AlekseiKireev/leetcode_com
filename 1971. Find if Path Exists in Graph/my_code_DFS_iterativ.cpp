class Solution {

private:

vector<bool> Visited;

void DFS(const vector<vector<int>>& AdjacencyList, const int source, const int destination){

    stack<int> VertexBuffer; VertexBuffer.push(source);
    Visited[source] = true;

    while(VertexBuffer.empty() == false){

        int Vertex = VertexBuffer.top();
        VertexBuffer.pop();

        for(int ver : AdjacencyList[Vertex]){

            if(Visited[ver] == false){

                Visited[ver] = true;
                if(ver == destination){return;}

                VertexBuffer.push(ver);
            }

        }
       
    }

}

public:
    bool validPath(const int n, const vector<vector<int>>& edges, const int source, const int destination) {
        
        if(source == destination){return true;}

        Visited.resize(n);  
        vector<vector<int>> AdjacencyList(n);
        
        for(const auto edge : edges){

            AdjacencyList[edge.front()].push_back(edge.back());
            AdjacencyList[edge.back()].push_back(edge.front());

        }

        DFS(AdjacencyList, source, destination);

        return (Visited[source] == Visited[destination]); // <--> return Visited[destination];
    }
};
