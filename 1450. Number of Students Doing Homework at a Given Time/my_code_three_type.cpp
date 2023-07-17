class Solution {

struct events{
int val;
int type;
};

public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        vector<events> Events;
        Events.reserve(endTime.size() + 1);

        for(int i = 0; i < endTime.size(); ++i){
            
            Events.push_back({startTime[i], 1});
            Events.push_back({endTime[i], -1});
        }

        Events.push_back({queryTime, 0});
        /*
        [5, 7], [5, 9]
        [8, 11], [11, 16]
        */
        sort(Events.begin(), Events.end(), [](const events l, const events r){
            /*
            l.val < r.val -- сортировка по возрастанию
            r.type < l.type -- сортировка по убыванию
            */
            return l.val < r.val || (l.val == r.val && r.type < l.type); 
        }
        );

        // "Return the number of students doing their homework at time queryTime"
        int ans = 0;

        for(auto [val, type] : Events){
            
            ans += type;
            if(type == 0){return ans;}
        }

        return ans;
    }
};
