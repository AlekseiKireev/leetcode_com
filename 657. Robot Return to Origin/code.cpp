class Solution {

unordered_map<char, pair<int,int> > SideToCoord = {
    {'U', {0,1}},
    {'D', {0,-1}},
    {'R', {1,0}},
    {'L', {-1,0}}
};

public:
    bool judgeCircle(string moves) {

        int x = 0;
        int y = 0;

        for(char move : moves){

            auto [dx,dy] = SideToCoord[move];
            x+=dx;
            y+=dy;

        }

        return (x == 0 && y == 0);
    }
};
