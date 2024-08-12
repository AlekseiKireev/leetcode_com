class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> map;
        
        for (int n : nums) {

            if (map.count(n) == 0) {
                int left = map.count(n - 1) ? map[n - 1] : 0;
                int right = map.count(n + 1) ? map[n + 1] : 0;
                
                int sum = left + right + 1;                
                
                res = max(res, sum);
                
                map[n] = sum;
                map[n - left] = sum;
                map[n + right] = sum;
            }

        }
        
        return res;
    }
};

/*
class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        int res = 0;
        std::unordered_map<int, int> map;
        
        for (int n : nums) {

            if (map.count(n) == 0) {
                int left = map.count(n - 1) ? map[n - 1] : 0;
                int right = map.count(n + 1) ? map[n + 1] : 0;
                
                int sum = left + right + 1;                
                
                res = max(res, sum);
                
                map[n] = sum;
                map[n - left] = sum;
                map[n + right] = sum;
                cout << "num: " << n << ' ' << "range: " << sum << '\n';
            }

        }

        cout << '\n';
        for(auto [num, range] : map){
            cout << "num: " << num << ' ' << "range: " << range << '\n';
        }
        
        return res;
    }
};
*/
/*
num: 100 range: 1
num: 4 range: 1
num: 200 range: 1
num: 1 range: 1
num: 3 range: 2
num: 2 range: 4

num: 2 range: 4
num: 3 range: 2
num: 1 range: 4
num: 200 range: 1
num: 4 range: 4
num: 100 range: 1
*/
