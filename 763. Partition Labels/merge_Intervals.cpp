// аналог: 
// https://leetcode.com/problems/merge-intervals/description/
// https://github.com/SkosMartren/leetcode_com/tree/main/56.%20Merge%20Intervals

class Solution {
public:
    vector<int> partitionLabels(string_view s) {
        
        vector<vector<int>> intervals(26, vector<int>(2, -1));

        for(int i = 0; i < s.size(); ++i){
            if(intervals[s[i] - 'a'].front() == -1){intervals[s[i] - 'a'] = {i,i};}
            else{intervals[s[i] - 'a'].back() = i;}
        }

        vector<vector<int>> Covers;

        for(int i = 0; i < s.size(); ++i){

            if(Covers.empty() || Covers.back().back() <  intervals[s[i] - 'a'].front()){ // Covers пустой или нет пересечений  
                Covers.push_back(intervals[s[i] - 'a']);
            }else{
                Covers.back().back() = max(Covers.back().back(), intervals[s[i] - 'a'].back());
            }

        }

        intervals.clear();
        vector<int> Ans;Ans.reserve(Covers.size());

        for(auto Cover : Covers){
            Ans.push_back(Cover.back() - Cover.front() + 1);
        }

        return Ans;
    }
};
/*
max в 23 строке необходим ввиду того, что есть два вида пересечения: 

инваринат b1 <= a1 ввиду sort

        /1/
interval                      a1|--|a2
Covers.back()            b1|-------------|b2

        /2/
interval                       a1|----------|a2
Covers.back()             b1|-------|b2   



*/
