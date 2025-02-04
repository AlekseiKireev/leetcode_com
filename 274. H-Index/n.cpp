/*
Найти: 
Индекс хирша определяется как максимальное значение h, 
при котором данный исследователь опубликовал не менее h статей, 
каждая из которых цитировалась не менее h раз.
*/
class Solution {
public:

    int hIndex(vector<int>& citations) {
        int n = citations.size(); // количество статей
        // "n + 1" --> Максимальное значение h-index не может превышать n (количество статей).
        vector<int> buckets(n + 1, 0); // buckets[i] отображает в количество статей, которые цитировались >= i раз
        
        for(int c : citations) {

            buckets[min(n,c)]++;

        }
        
        int count = 0;
        // накопление количество статей, которые имеют не менее i цитирований. 
        for(int i = n; i >= 0; i--) { 
            count += buckets[i];
            if(count >= i) {
                return i;
            }
        }
        
        return 0;
    }

};
