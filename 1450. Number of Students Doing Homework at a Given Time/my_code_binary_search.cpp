class Solution {

public:

    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin() ,endTime.end());
		
        // количество студентов, начавших делать работу к моменту времени queryTime включительно
        const int CountStarting = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
		
         // количество студентов, окончивших делать работу к моменту времени queryTime
        const int CountEnding = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();

        return CountStarting - CountEnding;
    }
    
};

/* 
количетсво студентов делающих работу в момент времени queryTime 
= 
количетсво студентов начавших делать в момент времени <= queryTime
-
количетсво студентов окончавших делать в момент времени < queryTime
*/
