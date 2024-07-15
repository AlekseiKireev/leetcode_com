class Solution {
    
pair<int,int> FindExtrem(vector<int>& nums, auto comp, int GlobalExtrem){

    int ExtremF = GlobalExtrem;
    int ExtremS = GlobalExtrem;

    for(int num : nums){
        if(comp(num, 0) && comp(num, ExtremF) ){
            ExtremS = ExtremF;
            ExtremF = num;
        } else if ( comp(num, ExtremS) ) {
            ExtremS =  num;
        }
    }

    return {ExtremF, ExtremS};

}

public:
    int maxProduct(vector<int>& nums) {
        auto [F, S] = FindExtrem(nums, greater<int>(), INT_MIN); // также надо сделать проверку на то, что F, S != INT_MIN
        return (F-1)*(S-1);
    }

};

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int,int> FindExtrem(const vector<int>& nums, auto comp, int GlobalExtrem){

    int ExtremF = GlobalExtrem;
    int ExtremS = GlobalExtrem;

    for(int num : nums){
        if(comp(num, 0) && comp(num, ExtremF) ){
            ExtremS = ExtremF;
            ExtremF = num;
        } else if ( comp(num, ExtremS) ) {
            ExtremS =  num;
        }
    }

    return {ExtremF, ExtremS};

}

// Функция для нахождения пары с максимальным произведением
pair<int, int> findMaxProductPair(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must have at least two elements.");
    }

    pair<int, int> minPair = FindExtrem(arr, greater<int>(), INT_MIN);
    pair<int, int> maxPair = FindExtrem(arr, less<int>(), INT_MAX);

    int product1 = minPair.first * minPair.second;
    int product2 = maxPair.first * maxPair.second;

    return (product1 > product2) ? minPair : maxPair;
}

int main() {
    vector<int> arr = {1, -4, 3, -6, 7, 0};
    try {
        pair<int, int> result = findMaxProductPair(arr);
        cout << "Pair with maximum product: (" << result.first << ", " << result.second << ")" << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
*/
