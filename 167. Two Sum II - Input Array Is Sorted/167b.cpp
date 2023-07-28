class Solution { 

public:

  vector<int> twoSum(const vector<int>& a, int target) { 
     unordered_map<int, int> valueToIndex;

     for (int i = 0; i < (int)a.size(); i++) {

       auto it = valueToIndex.find(target - a[i]); 

       if (it != valueToIndex.end()) {return {it->second + 1, i + 1};}
       valueToIndex[a[i]] = i;

     }
     
     throw invalid_argument("no sum target");
  }

};

