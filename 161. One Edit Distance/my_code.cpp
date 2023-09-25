#include<iostream>

class Solution {
    
 private:
    const int MinLeng;
    const int MaxLeng;
    
    // insertion, deletion or substitution
    
    bool Replace(string_view First, string_view Second){
        
        int CountDifference = 0;
        
        for(int i = 0; i < MinLeng; ++i){
            
            CountDifference += (First[i] != Second[i]);
            if(CountDifference > 1){return false;}
        }
        
        return (CountDifference == 1);
        
    }
    
    bool Delete(string_view First, string_view Second){
        
        for(int i = 0; i < MinLeng; ++i){
            
            if(First[i] != Second[i]){ // delete Second[i]
                return ();
            }
        }        
        
        
        return false;        
    }    
        
    bool Insert(string_view First, string_view Second){
        

    }
    
 public:
 
  bool isOneEditDistance(string_view First, string_view Second) {
        
        MinLeng = First.size();
        MaxLeng = Second.size();
        
        if(MinLeng > MaxLeng){return isOneEditDistance(Second, First);}
        
        assert(MinLeng <= MaxLeng);
        if(MaxLeng - MinLeng > 1){return false;}    
        
        assert(MinLeng == MaxLeng || MinLeng == MaxLeng + 1);
        
        return ((MinLeng == MaxLeng) ? Replace(First, Second) : (Delete(First, Second) || Insert(First, Second)) );
        
    
  }
  
};
