const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class Solution {

public:

  vector<int> topKFrequent(const vector<int>& a, int k) {

    unordered_map<int, int> count; // a[i] -> number of equal
    for (int x : a) {
      count[x]++;
    }

    unordered_map<int, vector<int>> countToKeys; // frequency -> list of keys 
    for (auto kv : count) {
      int cnt = kv.second;
      int key = kv.first;
      countToKeys[cnt].push_back(key);
    }

    vector<int> freq; // list of frequencies
    for (auto kv : countToKeys) {
      freq.push_back(kv.first);
    }
    sort(freq.rbegin(), freq.rend());

    vector<int> ans;
    for (int f : freq) {
      for (int key : countToKeys[f]) {
        ans.push_back(key);
        if ((int)ans.size() == k) {
          return ans;
        }
      }
    }

    throw invalid_argument("no k different elements");
  }

};

