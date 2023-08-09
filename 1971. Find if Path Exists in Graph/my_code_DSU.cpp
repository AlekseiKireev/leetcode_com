class DSU{

private:

int StartNumberLiders;

vector<int> Parent;
vector<int> Size;

public:

DSU(int n) : StartNumberLiders(n){

    Parent.resize(StartNumberLiders);
    Size.resize(StartNumberLiders, 1);

    for(int i = 0; i < StartNumberLiders; ++i){Parent[i] = i;}

}

int Find(const int x){

    return (Parent[x] == x) ? x : Parent[x] = Find(Parent[x]);

}

void Union(int U, int V){

    int LiderU = Find(U);
    int LiderV = Find(V);

    if(LiderU == LiderV){return;}

    if(LiderV < LiderU){
        
        swap(LiderV, LiderU);
    }

    assert(LiderU <= LiderV);

    Parent[LiderV] = LiderU;
    Size[LiderV] += LiderU;

}

};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        DSU dsu(n);

        for(auto edge : edges){

            dsu.Union(edge.front(), edge.back());

        }

        return (dsu.Find(source) == dsu.Find(destination));

    }
};
