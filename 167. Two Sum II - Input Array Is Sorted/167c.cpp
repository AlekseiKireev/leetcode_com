class Solution {
public:
    vector<int> twoSum(const vector<int>& a, int target) {
        for (int i = 0; i < (int)a.size(); i++) {

            int j = (int)(upper_bound(a.begin(), a.end(), target - a[i]) - a.begin()) - 1;

            // if (j != i && a[j] == target - a[i]) {return { i + 1, j + 1 };} // equiv
            assert(j > i);
            if (a[j] == target - a[i]) {return { i + 1, j + 1 };}      

        }

        throw invalid_argument("no sum target");
        
    }
};
