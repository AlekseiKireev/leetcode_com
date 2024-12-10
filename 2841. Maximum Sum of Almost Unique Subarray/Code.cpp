class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {

        long long Uniq = 0, MaxPrefsum = 0, Prefsum = 0;
        unordered_map<int, int> NumToCount;

        for(int Right = 0, Left = 0; Right < nums.size(); ++Right){

            Prefsum += nums[Right];

            if(++NumToCount[nums[Right]] == 1) { // подсчет уникальных элементов
                Uniq++;
            }

            if(Right >= k){ // формирование окна длины k

                Prefsum -= nums[Left];

                if(--NumToCount[nums[Left]] == 0) {Uniq--;}

                Left++;
            }

            if(Uniq >= m && Right - Left + 1 == k) { // формирование ответа
                MaxPrefsum = max(MaxPrefsum, Prefsum);
            }
        }
        return MaxPrefsum;
    }
};
