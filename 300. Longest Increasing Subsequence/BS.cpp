class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seen;
        for (int num : nums) {
            if (seen.empty() || seen.back() < num) {
                seen.push_back(num);
            } else {
                auto it = ranges::lower_bound(seen, num); // Find the index of the first element >= num
                *it = num; // Replace that number with num
            }
        }
        return seen.size();
    }
};
/*
В приведённых шагах нам пришлось хранить несколько подмассивов (sub1, sub2..., subk), что снижает производительность. 
Однако можно хранить только один массив sub: если новое число x не больше последнего элемента sub, мы выполняем бинарный поиск, 
чтобы найти наименьший элемент >= x в sub, и заменяем его на x.
*/
