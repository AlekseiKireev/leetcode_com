class Solution {

struct step{

int x;
int y;

};

public:

    bool isRobotBounded(string_view instructions) {
        

        int X = 0;
        int Y = 0;

        int SideWorld = 0;


        array<step, 4> Steps = {
            {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0}
            }

        };
        for(const char move : instructions){

            if(move == 'G'){ 

                X += Steps[SideWorld].x;
                Y += Steps[SideWorld].y;

            }else if(move == 'L') { 
                SideWorld = (SideWorld + 3) % 4;
            }else if(move == 'R') { 
                SideWorld = (SideWorld + 1) % 4;
            }

        }

        return (X == 0 && Y == 0) || SideWorld != 0; 

    }
};
