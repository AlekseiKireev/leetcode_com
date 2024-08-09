class Solution {
public:
    vector<string> restoreIpAddresses(string& s) {
        
        vector<string> Ans;
        if(s.size()>12){
            return Ans;
        }

        for(int Chunk1 = 1; Chunk1 <= 3; ++Chunk1){
            for(int Chunk2 = 1; Chunk2 <= 3; ++Chunk2){
                for(int Chunk3 = 1; Chunk3 <= 3; ++Chunk3){
                    for(int Chunk4 = 1; Chunk4 <= 3; ++Chunk4){

                        // 1.01023
                        if(Chunk1 + Chunk2 + Chunk3 + Chunk4 == s.size()){

                            int IntChunk1 = stoi(s.substr(0, Chunk1)); 
                            int IntChunk2 = stoi(s.substr(Chunk1, Chunk2));  
                            int IntChunk3 = stoi(s.substr(Chunk1 + Chunk2, Chunk3));  
                            int IntChunk4 = stoi(s.substr(Chunk1 + Chunk2 + Chunk3, Chunk4)); 

                            if(IntChunk1 > 255 || IntChunk2 > 255 || IntChunk3 > 255 || IntChunk4 > 255){
                                continue;
                            }

                            string Buf = 
                            to_string(IntChunk1) + "." + 
                            to_string(IntChunk2) + "." + 
                            to_string(IntChunk3) + "." + 
                            to_string(IntChunk4) ;
                            
                            if( Buf.size() == s.size() + 3 ){
                                Ans.push_back(Buf);
                            }

                        }

                    }    
                }                
            }
        }

        return Ans;

    }
};
