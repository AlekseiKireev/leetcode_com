class Solution {

struct Pair{
int x;
int y;

    bool operator==(const Pair Other) const {
        return (x == Other.x && y == Other.y);
    }

};

struct PairHash{

    size_t operator()(const Pair Other) const {
        return Other.x ^ Other.y;
    }
};

unordered_map<char, Pair > SideToCoord = {
    {'N', {0,1}},
    {'S', {0,-1}},
    {'E', {1,0}},
    {'W', {-1,0}}
};

public:
    bool isPathCrossing(string path) {
        
        int x = 0;
        int y = 0;
        unordered_set<Pair, PairHash> Visited;
        Visited.insert({0,0});
        
        for(char ch : path){

            x += SideToCoord[ch].x;
            y += SideToCoord[ch].y;

            if(Visited.count({x,y})){
                return true;
            }
            Visited.insert({x,y});
        }

        return false;
    }
};
