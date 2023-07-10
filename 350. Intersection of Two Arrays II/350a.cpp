class Solution {

public:

   vector<int> intersect(const vector<int>& aa, const vector<int>& bb) { 
     const vector<int> &a = aa.size() < bb.size() ? aa : bb;
     const vector<int> &b = aa.size() < bb.size() ? bb : aa; 
     
     unordered_map<int,int> count;
     for (int v : a) {count[v]++;}
     
     vector<int> ans;
     
     for (int v : b) {
        auto it = count.find(v);
        if (it != count.end() && it->second > 0) {
          ans.push_back(v);
          it->second--;
        }
     }
     
     return ans;
   }

};
