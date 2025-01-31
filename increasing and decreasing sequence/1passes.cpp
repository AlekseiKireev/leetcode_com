#include <iostream>
#include <vector>

struct Result {
    int max_inc_length = 0, max_inc_start = -1;
    int max_dec_length = 0, max_dec_start = -1;
};

Result findMaxIncreasingDecreasing(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    
    int n = arr.size();
    Result res;
    
    int inc_len = 1, inc_start = 0;
    int dec_len = 1, dec_start = 0;
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            ++inc_len;
        } else {
            if (inc_len > res.max_inc_length) {
                res.max_inc_length = inc_len;
                res.max_inc_start = inc_start;
            }
            inc_len = 1;
            inc_start = i;
        }
        
        if (arr[i] < arr[i - 1]) {
            ++dec_len;
        } else {
            if (dec_len > res.max_dec_length) {
                res.max_dec_length = dec_len;
                res.max_dec_start = dec_start;
            }
            dec_len = 1;
            dec_start = i;
        }
    }
    
    if (inc_len > res.max_inc_length) {
        res.max_inc_length = inc_len;
        res.max_inc_start = inc_start;
    }
    
    if (dec_len > res.max_dec_length) {
        res.max_dec_length = dec_len;
        res.max_dec_start = dec_start;
    }
    
    return res;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 1, 5, 6, 7, 2, 1};
    Result res = findMaxIncreasingDecreasing(arr);
    
    std::cout << "Max Increasing Length: " << res.max_inc_length << ", Start Index: " << res.max_inc_start << '\n';
    std::cout << "Max Decreasing Length: " << res.max_dec_length << ", Start Index: " << res.max_dec_start << '\n';
    
    return 0;
}
