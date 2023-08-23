class Solution {

private:

struct Interval{

    int LeftBorder = -1;
    int RightBorder = -1;

};


public:
    vector<int> partitionLabels(string_view s) {
        
        // Так как i возрастает, то Intervals отсортирован по LeftBorder
        vector<Interval> Intervals(26); // 26 <-- "s consists of lowercase English letters."
        for(int i = 0; i < s.size(); ++i){

            if(Intervals[s[i] - 'a'].LeftBorder == -1){

                Intervals[s[i] - 'a'] = {i,i};

            }else{

                Intervals[s[i] - 'a'].RightBorder = i;

            }

        }

        vector<Interval> Covers;
        Covers.reserve(s.size());
        Covers.push_back(Intervals[s[0] - 'a']);

        for(int i = 1; i < s.size(); ++i){

            if(Covers.back().RightBorder < Intervals[s[i] - 'a'].LeftBorder){ // нет пересечения
                Covers.push_back(Intervals[s[i] - 'a']);
            }else{
                Covers.back().RightBorder = max(Covers.back().RightBorder, Intervals[s[i] - 'a'].RightBorder);

            }

        }

        Covers.shrink_to_fit();
        Intervals.clear();
        vector<int> SizeChanks; 
        SizeChanks.reserve(Covers.size());


        for(auto cover : Covers){
            SizeChanks.push_back(cover.RightBorder - cover.LeftBorder + 1);
        }
        
        assert(Covers.size() <= 26); // true --> в 33 стркое можно выделить константное количество памяти!
        return SizeChanks;

    }
};

/*
max в 41 строке необходим ввиду того, что есть два вида пересечения: 

инваринат b1 <= a1 ввиду sort Intervals

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
