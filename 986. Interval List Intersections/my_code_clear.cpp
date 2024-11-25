/*
Time complexity: O(firstList.size() + secondList.size())
Space complexity: O(max(firstList.size(), secondList.size()))
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> Intersection; // O(max(firstList.size(), secondList.size())). Пример: firstList = {{1,100}}, secondList = {{2,3},{4,5}}
        if(firstList.empty() || secondList.empty()){return Intersection;}

        int firstPtr = 0;
        int secondPtr = 0;
        
        // O(firstList.size() + secondList.size())
        while(firstPtr < firstList.size() && secondPtr < secondList.size()){ 

            int LeftBorderSegment = max(firstList[firstPtr].front(), secondList[secondPtr].front());
            int RightBorderSegment = min(firstList[firstPtr].back(), secondList[secondPtr].back());

            const bool CheckIntersection = LeftBorderSegment <= RightBorderSegment;

            if(CheckIntersection){Intersection.push_back({LeftBorderSegment, RightBorderSegment});}

            (firstList[firstPtr].back() <= /* "<" тоже работает*/ secondList[secondPtr].back()) ? ++firstPtr : ++secondPtr; 

        }



        return Intersection;

    }
};
