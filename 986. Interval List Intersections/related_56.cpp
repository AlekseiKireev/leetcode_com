class Solution {

private:

    bool CheckIntersectionSortedIntervals(vector<int>& First, vector<int>& Second){

        return max(First.front(), Second.front()) <= min(First.back(), Second.back());
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> Ans;

        // как только один из контейнеров кончиться, нет смысла проверять остатки оствашегося, так как "Each list of intervals is pairwise disjoint"
        for(int FirstPtr = 0, SecondPtr = 0; FirstPtr < firstList.size() && SecondPtr < secondList.size(); ){ 

            if( CheckIntersectionSortedIntervals(firstList[FirstPtr], secondList[SecondPtr]) ){

                Ans.push_back({max(firstList[FirstPtr].front(), secondList[SecondPtr].front()), 
                                min(firstList[FirstPtr].back(), secondList[SecondPtr].back())});

            }

            // у кого правая сторона меньше, ту и сдвигаем, та как большая сторона может иметь пересечения с следущюим элементом
            firstList[FirstPtr].back() < secondList[SecondPtr].back() ? ++FirstPtr : ++SecondPtr;
        }

        return Ans;

    }
};
