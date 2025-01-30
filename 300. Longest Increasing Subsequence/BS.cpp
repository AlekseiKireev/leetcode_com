class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> Buf;
        for (int num : nums) {
            if (Buf.empty() || Buf.back() < num) {
                Buf.push_back(num);
            } else {
                auto it = ranges::lower_bound(Buf, num); // Find the index of the first element >= num
                *it = num; // Replace that number with num
            }
        }
        return Buf.size();
    }
};
/*
В приведённых шагах нам пришлось хранить несколько подмассивов (sub1, sub2..., subk), что снижает производительность. 
Однако можно хранить только один массив sub: если новое число x не больше последнего элемента sub, мы выполняем бинарный поиск, 
чтобы найти наименьший элемент >= x в sub, и заменяем его на x.
*/
