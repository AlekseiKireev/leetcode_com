/*
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    int busyStudent(const vector<int>& startTime, const vector<int>& endTime, int queryTime) {
        
        int ans = 0;

        for(int i = 0; i < startTime.size(); ++i){
            
            /* // тест демонстрирует что данные не отсортированы. Было бы это так -- вместо continue можно использовать break
            [9,8,7,6,5,4,3,2,1]
            [10,10,10,10,10,10,10,10,10]
            5
            */
            if(queryTime < startTime[i]){continue;} // -->     startTime[i] <= queryTime       
            if(/*startTime[i] <= queryTime && */queryTime <= endTime[i]) {++ans;}
                       
        }

        return ans;
    }
};
