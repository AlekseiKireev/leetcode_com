class Solution {
    
 private:
 
    struct Event{
      
      int Val;
      int Type;
      
      bool operator<(const Event L, const Event R) const {
          return (L.Val == R.Val ? L.Type < R.Type : L.Val < R.Val);
      }

    };     

 private:
 
  int MNCR = 0; // Minimum Number of Conference Rooms 
     
 public:
 
    int minMeetingRooms(vector<vector<int>>& intervals) {
    
        vector<Event> events; events.reserve(2 * intervals.size()); // "2 * " <-- укладывания концов в intervals в events 
        
        for(int i = 0; i < intervals.size(); ++i){
            
            const auto event = events[intervals.size() - 1 - i];
            events.pop_back();
            
            events.push_back({event.front(), 1});
            events.push_back({event.back(), -1});
            
        }
        
        sort(events.begin(), events.end());
        
        int CurrentNCR = 0;
        
        for(const auto [val, type] : events){
            CurrentNCR += type;
            max(MNCR, CurrentNCR);
        }
        
        
        return MNCR;
    
    }
  
};
