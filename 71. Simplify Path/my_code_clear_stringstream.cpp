/*
Time complexity : O(n)
Space complexity : O(n)
*/ 
class Solution {
public:
    string simplifyPath(string& path) {
        
        stringstream ss(path);
        vector<string> Data;

        for(string Buffer; getline(ss,Buffer,'/');){
            
            if(Buffer.empty() || Buffer == "."){continue;}

            if(Buffer == ".." && !Data.empty()){
                Data.pop_back();
                continue;
            }

            if(Buffer != ".."){ // услонвый оператор нужен на случай, если Data.empty() == true (см. условный оператор выше), например: path = "/../"  Output "/.." Expected "/"
                Data.push_back(Buffer);
            }
        }

        string new_path;

        for(string& path : Data){
            new_path += ("/" + path );
        }
        

        return new_path.empty() ? "/" : new_path;
    }
};
