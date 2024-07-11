class Solution {

private:

    int PrefixSize = 0; // количество начальных нулей
    int SuffixSize = 0; // максимальное количетство нулей, отличных от начальных и конечных
    int EndingSize = 0; // количество конечных нулей. Также выступает в качестве буффера для EndingSize преследуя цель максимизации

public:
    int maxDistToClosest(vector<int>& seats) {
        
        const int SIZE = seats.size();
        for(int seat : seats){ // обрабатываем случай ведущих нулей, например: [0,0,0,0,0,1,0,0,0]
            if(seat){break;}
            ++PrefixSize;
        }

        while(seats.back() == 0){
            seats.pop_back();
            ++EndingSize;
        }

        int Idx = -1;
        int LocalMaxSuffixSize = 0;
        for(int i = PrefixSize; i<seats.size(); ++i){ /* [1,1,0,0,0,0,1] --> idx = 6 - (4 + 1)/2 = 4
                                                         [1,1,0,0,0,0,0,1] --> idx = 7 - (5 + 1)/2 = 4
                                                      */
            if(!seats[i]){ // место свободно, заносим информацию в буффер
                ++LocalMaxSuffixSize;
            }
            else{

                if(SuffixSize < LocalMaxSuffixSize ) {Idx = i - (LocalMaxSuffixSize+1)/2;}
                SuffixSize = max(SuffixSize, LocalMaxSuffixSize);
                
                LocalMaxSuffixSize = 0; // обнуляем буффер 
            }

        }

        int GlobalMax = max({PrefixSize,(SuffixSize + 1)/2 ,EndingSize});
        
        if(GlobalMax == (SuffixSize + 1)/2){cout << Idx;}
        if(GlobalMax== PrefixSize){cout << 0;}
        if(GlobalMax== EndingSize){cout << SIZE - 1;}

        return GlobalMax; 
    }
};
