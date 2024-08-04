class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string, string> AtoB;
        for(auto path : paths){
            AtoB[path[0]] = path[1];
        }

        auto Start = paths[0][0];
        while(AtoB[Start] != ""){

            Start = AtoB[Start];
        }

        return Start;

    }   
};
