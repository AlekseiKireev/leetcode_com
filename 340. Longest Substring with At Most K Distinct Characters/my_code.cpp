class Solution{
  
  private:
  
    const int SIZE_ALPHABET = 26;
      
  public:
  
    int longestKSubstr(string_view s, int k) { // "0 <= k <= 50"
        
        array<int, SIZE_ALPHABET> CharToCount; CharToCount.fill(0);
        
        int LengthSubstr = -1;
        
        for(int RightBorderWindow = 0, LeftBorderWindow = 0; RightBorderWindow <=  nums.size() - 1; ++RightBorderWindow){ // move Right ptr
          
           if(++CharToCount[RightBorderWindow] == 1){ // новая буква (CharToCount[RightBorderWindow]) в sliding window
                --k;
            }
          
          /* // лучше не сдвигать двумя способами правй указатель, не удобно / понижает читабельность / повышает вероятность ошибки
            while(RightBorderWindow < nums.size() - 1 && k >= 0){
                
                    if(++CharToCount[RightBorderWindow] == 1){ // новая буква (CharToCount[RightBorderWindow]) в sliding window
                        --k;
                    }
                    ++RightBorderWindow;
                
            } // RightBorderWindow указывет на последний или за последний символ sliding window ????
            */
            
            while(LeftBorderWindow < RightBorderWindow && k < 0){ // move Left ptr
                              
                if(--CharToCount[LeftBorderWindow] == 0){
                    ++k;
                }
                ++LeftBorderWindow;
            } // LeftBorderWindow указывет на первый символ sliding window
            
            LengthSubstr = max(LengthSubstr, RightBorderWindow - LeftBorderWindow + 1);
                
        }
        
        return LengthSubstr;
    }
    
};

/*
НАПИСАТЬ ТЕСТЫ
aaaa 1
aaaa 2 
aaaa 4
aaaa 42 
*/

