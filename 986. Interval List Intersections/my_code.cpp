class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> Intersection; // O(max(firstList.size(), secondList.size()))
        if(firstList.empty() || secondList.empty()){return Intersection;}

        // "0 <= firstList.length, secondList.length <= 1000"
        int firstPtr = 0;
        int secondPtr = 0;
        
        // O(firstList.size() + secondList.size())
        while(firstPtr < firstList.size() && secondPtr < secondList.size()){ // AND использутеся по той причине, что ищем пересечение, и как только один из указатлей обработал весь vector, далее пересечений, очевидно, быть не может

            int LeftBorderSegment = max(firstList[firstPtr].front(), secondList[secondPtr].front());
            int RightBorderSegment = min(firstList[firstPtr].back(), secondList[secondPtr].back());

            const bool CheckIntersection = LeftBorderSegment <= RightBorderSegment;

            if(CheckIntersection){Intersection.push_back({LeftBorderSegment, RightBorderSegment});}


            // инкрементация происходит в самом конце, иначе даже самый первый случай может быть обработан не верно, т.е. сначала обрабатываем текущие значения указателей (они определены по условию), потом сдвигам
            (firstList[firstPtr].back() <= /* "<" тоже работает*/ secondList[secondPtr].back()) ? ++firstPtr : ++secondPtr; 
            // Докажем корректность условия сдвига от противного: 
            // если сдвигать первый указатель по условию "firstList[firstPtr].back() > secondList[secondPtr].back()" 
            // то можно построить контрпример: firstList = [[0,4],[6,10]], secondList = [[1,2], [3,4]]
        }



        return Intersection;

    }
};
