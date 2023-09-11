class Solution {

struct step{

int x;
int y;

};

public:

    bool isRobotBounded(string_view instructions) {
        
        // "On an infinite plane, a robot initially stands at (0, 0) and faces north. "
        int X = 0;
        int Y = 0;

        int SideWorld = 0;

        /*
The north direction is the positive direction of the y-axis.
The south direction is the negative direction of the y-axis.
The east direction is the positive direction of the x-axis.
The west direction is the negative direction of the x-axis.
        */

        /*
        direction


            N
            |
            |
        W --------- E
            |
            |
            S

        
        
        SideWorld

            0
            |
            |
        3 --------- 1
            |
            |
            2     
        */

        array<step, 4> Steps = {
            {
                {0, 1}, {1, 0}, {0, -1}, {-1, 0}
            }

        };
        for(const char move : instructions){

            if(move == 'G'){ // ""G": go straight 1 unit."

                X += Steps[SideWorld].x;
                Y += Steps[SideWorld].y;

            }else if(move == 'L') { // ""L": turn 90 degrees to the left (i.e., anti-clockwise direction)."
                SideWorld = (SideWorld + 3) % 4;
            }else if(move == 'R') { // ""R": turn 90 degrees to the right (i.e., clockwise direction)."
                SideWorld = (SideWorld + 1) % 4;
            }

        }

        return (X == 0 && Y == 0) || SideWorld != 0;

    }
};

