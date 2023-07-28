class Solution {
public:

    vector<int> twoSum(const vector<int>& a, int target) {
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = i + 1; j < (int)a.size(); j++) {
              
                if (a[i] + a[j] == target) {return { i + 1, j + 1 };}
              
            }
        }
      
        throw invalid_argument("no sum target");
    }

};
