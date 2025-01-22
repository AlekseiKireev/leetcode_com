class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); // это гарантирует, что intervals[i-1].front() <= intervals[i].front()
        
        for(int i = 1; i < intervals.size(); ++i){
                if(intervals[i].front() < intervals[i-1].back()){return false;}
        }
        
        return true;
        
    }
};
/*
после сортировки интревалы имеют вид: 
a1|---------------------------------------------------|b1
        a2|-----------------------------------|b2
                a3|---------------------|b3
                a4|----------|b4                

Достаточно проверить, что a_{i} < b_{i-1}

Ответ: True                
*/
