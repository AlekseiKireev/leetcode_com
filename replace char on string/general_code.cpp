 #include <iostream>
 #include <string>
 #include <algorithm>
 
using namespace std;

void ReplaceCharToStr(string& Str, const char ReplCh, const string& ReplStr){
    
    const int STR_SIZE = Str.size();
    const int REPLSTR_SIZE = ReplStr.size();
    
    int CountReplCh = 0;
    for(char ch : Str){
        CountReplCh += (ch == ReplCh);
    }
    
    Str.resize(STR_SIZE + (REPLSTR_SIZE - 1)*CountReplCh);
    int NewPtr = Str.size() - 1;
    
    for(int OldPtr = STR_SIZE - 1; OldPtr >= 0; --OldPtr){
        
        if(Str[OldPtr] == ReplCh){
            
            for(char ch : ReplStr){
                Str[NewPtr] = ch;
                --NewPtr;
            }
            
        }else{
            Str[NewPtr] = Str[OldPtr];
            --NewPtr;            
            
        }
    }
    
    
    
}

int main(){

     string str = " Mr  John Smith ";
     string ReplStr = "$ABC";
     ranges::reverse(ReplStr);
     
     ReplaceCharToStr(str, ' ', ReplStr);
     cout << str << std::endl;     

    return 0;
}
