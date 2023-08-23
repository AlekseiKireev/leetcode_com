class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> Covers;
        Covers.reserve(intervals.size());

        Covers.push_back(intervals.front()); // <-- "1 <= intervals.length <= 10^4"

        for(const auto interval : intervals){
            
            if(max(interval.front(), Covers.back().front()) <= min(interval.back(), Covers.back().back())){ 

                Covers.back().back() = max(Covers.back().back(), interval.back());
            }else{
                Covers.push_back(interval);
            }
        }

        Covers.shrink_to_fit();
        return Covers;

    }
};
/*
max в 16 строке необходим ввиду того, что есть два вида пересечения: 

инваринат b1 <= a1 ввиду sort

        /1/
interval                      a1|--|a2
Covers.back()            b1|-------------|b2

        /2/
interval                       a1|----------|a2
Covers.back()             b1|-------|b2   

Нет пересечения: 

interval                                    a1|----------|a2
Covers.back()             b1|-------|b2  

*/
